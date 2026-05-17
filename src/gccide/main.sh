#!/bin/bash

log_c_file="/tmp/gcclog$$.c"
log_file="/tmp/gcclog$$"

new_code() {
cat > "$log_c_file" << 'EOF'
#include <stdio.h>

int main() {
    
    return 0;
}
EOF
}

add_line() {
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
		if [ -n "$new_line" ]; then
			add_line "$new_line"
		fi
		;;
	esac
done

rm -f "$log_c_file" "$log_file"
