#!/bin/bash

set -e

WORKINGPATH="$(pwd)"
SCRIPTPATH="$(
	cd -- "$(dirname "$0")" >/dev/null 2>&1
	pwd -P
)"

cd "$SCRIPTPATH/.."
cmake -S . -B build
cd "$SCRIPTPATH/../build"
make
"$SCRIPTPATH/../build/CollBot/CollBot"

cd "$WORKINGPATH"
