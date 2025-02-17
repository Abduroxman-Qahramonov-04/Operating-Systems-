#!/bin/bash

find "/home/kali" -type f -user "kali" -name "*.txt" -exec grep -H "main" {} \;