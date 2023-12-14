#!/bin/bash
CPU=O3CPU

python3 `which scons` build/X86/gem5.opt -j4

cd hy425

make OLOCAL

make OSTATIC

make OGAG

make OPAG