#!/usr/bin/env bash

SRC_FILE=$1
INPUT_FILE=$2

if [ -z "$SRC_FILE" ]; then
  echo "SRC_FILE not provided"
  exit
fi

if [ -z "$INPUT_FILE" ]; then
  echo "INPUT_FILE not provided"
  exit
fi

SRC_FILE_NAME=$(basename $SRC_FILE)
BIN_FILE="./out/${SRC_FILE_NAME/.cc/.out}"

mkdir -p ./out
clang++ $SRC_FILE -o $BIN_FILE
$BIN_FILE < $INPUT_FILE
