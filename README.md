# c2bash - Custom Bash Utils on C

A lightweight implementation of the Unix `cat` command with support for common flags.

## Build

```bash
make build
# or
make rebuild
```

## Usage

```bash
./cat [OPTIONS] [FILE]
```

If no file is specified, reads from stdin.

## Options

| Flag | Long form | Description |
|------|-----------|-------------|
| `-b` | `--number-nonblank` | Number only non-empty lines |
| `-e` / `-E` | - | Display `$` at line endings |
| `-n` | `--number` | Number all output lines |
| `-s` | `--squeeze-blank` | Squeeze multiple blank lines into one |
| `-t` / `-T` | - | Display tabs as `^I` |

## Examples

```bash
# Display file with line numbers
./cat -n test.txt

# Squeeze blank lines and show line endings
./cat -s -e test.txt

# Combine multiple flags
./cat -b -T test.txt

# Read from stdin
echo "hello" | ./cat -E
```

## Clean

```bash
make clean
```

## License

MIT
