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