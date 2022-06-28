#!/bin/bash

if $1; then
    echo "FALSE NEGATIVE! Expected success but failed"
    exit 1
else
    echo "Pass as expected"
fi
