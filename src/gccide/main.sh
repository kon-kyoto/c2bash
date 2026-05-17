#!/bin/bash

log_c_file="/tmp/gcclog$(date +%s%3N).c"
log_file="/tmp/gcclog$(date +%s%3N)"

# Проверяем существование файла (с кавычками!)
if [ -f "$log_c_file" ]; then
    # Если существует - добавляем суффикс
    log_c_file="/tmp/gcclog$(date +%s%3N)_$$.c"
    log_file="/tmp/gcclog$(date +%s%3N)_$$"
fi

# Создаем C файл
echo "#include <stdio.h>

int main() {
    // $log_file
    
    return 0;
}" > "$log_c_file"

# Компилируем
gcc "$log_c_file" -o "$log_file"

echo "Создан: $log_c_file -> $log_file"
