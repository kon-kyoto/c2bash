#!/bin/bash

log_c_file="/tmp/gcclog$$.c"
log_file="/tmp/gcclog$$"

headers=""
code_lines=""

new_code() {
	headers=""
	code_lines=""

cat > "$log_c_file" << 'EOF'
#include <stdio.h>

int main() {

return 0;
}
EOF
}

add_include() {
	local line="$1"
	local escaped_line=$(echo "$line" | sed 's/[\/&]/\\&/g')
	sed -i "/#include <stdio.h>/a\\$escaped_line" "$log_c_file"
}

add_define() {
	local line="$1"
	local escaped_line=$(echo "$line" | sed 's/[\/&]/\\&/g')
	sed -i "/^int main()/i\\$escaped_line" "$log_c_file"
}

add_code_line() {
	local line=$(echo "$1" | sed 's/[\/&]/\\&/g')
	sed -i "/return 0;/i\\    $line" "$log_c_file"
}

show_code() {
	cat "$log_c_file"
}

new_code

while true; do
	echo -n ">>> "
	read new_line

	[ -z "$new_line" ] && continue

	case "$new_line" in
		quit|exit)
			break
			;;
		run)
			echo "Start running..."
			if gcc "$log_c_file" -o "$log_file" 2>&1; then
			"$log_file"
			else
			echo "ERROR!"
			fi
			;;
		show)
			show_code
			;;
		clear)
			new_code
			;;
		*)
			if [[ "$new_line" =~ ^#[[:space:]]*include ]]; then
			add_include "$new_line"
			echo "[Add include] $new_line"
			elif [[ "$new_line" =~ ^#[[:space:]]*define ]]; then
			add_define "$new_line"
			echo "[Add define] $new_line"
			else
			add_code_line "$new_line"
			fi
			;;
	esac
done

rm -f "$log_c_file" "$log_file"
