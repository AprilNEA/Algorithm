#!/bin/bash

# 检查是否提供了文件名参数
if [ -z "$1" ]; then
  echo "Usage: $0 <filename.rs>"
  exit 1
fi

# 获取文件名和基名
filename=$1
# basename=$(basename "$filename" .rs)
# tmpdir=$(mktemp -d -t rust-XXXXXX)


# 编译 Rust 文件
# echo "Compiling $filename..."
rustc "$filename" -o "$TMPDIR/rust-script-temp"

# 检查编译是否成功
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# 运行生成的可执行文件
# echo "Running $basename..."
# "$tmpdir/$basename"
"$TMPDIR/rust-script-temp"

# 清理临时目录
#rm -rf "$tmpdir"
rm "$TMPDIR/rust-script-temp"
