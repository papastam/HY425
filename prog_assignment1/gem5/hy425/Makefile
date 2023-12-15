# Templates
# 
# LocalBP 	PredSize 	BitsPerCounter
# GagPred	GHRSize		PredTableWidth
# PagPred	LHTHeight	LHTWidth		GPTHeight	GPTWidth


TLOCAL:
	./runall.sh TimingSimpleCPU LocalBP 1024 2

OLOCAL:
	./runall.sh O3CPU LocalBP 1024 2

TSTATIC:
	./runall.sh TimingSimpleCPU StaticPred

OSTATIC:
	./runall.sh O3CPU StaticPred

TGAG:
	./runall.sh TimingSimpleCPU GAgPred 5 2

OGAG:
	./runall.sh O3CPU GAgPred 5 2

TPAG:
	./runall.sh TimingSimpleCPU PAgPred 256 5 32 2

OPAG:
	./runall.sh O3CPU PAgPred 256 5 32 2

clean_runs:
	rm -rf */m5out*

OVERNIGHT: OLOCAL OSTATIC OGAG OPAG

EXPLORE:
	# Do some exploration 
	./runall.sh O3CPU GAgPred 10 5
	./runall.sh O3CPU GAgPred 20 5
	./runall.sh O3CPU GAgPred 30 10

	./runall.sh O3CPU PAgPred 256 10 1024 5
	./runall.sh O3CPU PAgPred 512 10 1024 10
	./runall.sh O3CPU PAgPred 1024 20 2048 20

LIMITATIONS:
	# Limit the budget to 3072 entries
	./runall.sh O3CPU GAgPred 10 3
	./runall.sh O3CPU GAgPred 7 24

EXTREME_CASES:
	./runall.sh TimingSimpleCPU GAgPred 7 24
	./runall.sh TimingSimpleCPU PAgPred 64 16 32 64
	./runall.sh TimingSimpleCPU PAgPred 32 32 64 32
