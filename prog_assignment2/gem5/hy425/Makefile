# The default values of each parameter are:
# 
# 1. LSQ_ENTRIES: Number of LoadQueue/StoreQueue entries (same value for both)
# Range: 16, 32, 64, 128
# Default: 16
# Today: 128
# 
# 2. ROB_ENTRIES: Number of ReOrderBuffer entries
# Range: 64, 128, 256, 512
# Default: 64
# Today: 384
#
# 3. FUINT_NUM: Number of Functional Units of type INT
# Range: 2, 4, 8, 16
# Default: 2
# Today: 5
#
# 4. FUCOM_NUM: Number of Functional Units of type MUL/DIV
# Range: 2, 4, 8
# Default: 2
# Today: 2
#
# 5. FUFP_NUM: Number of Floating Point Function Units
# Range: 2, 4, 8
# Default: 2
# Today: 3
#
# 6. FULS_NUM: Number of Load/Store Functional Units
# Range: 1, 2, 4
# Default: 1
# Today: 3

# The first step is run each value of each parameter whiel keeping the others in default value.
first_step:
	./runall.sh 16 64 2 2 2 1

	./runall.sh 32 64 2 2 2 1
	./runall.sh 64 64 2 2 2 1
	./runall.sh 128 64 2 2 2 1

	./runall.sh 16 128 2 2 2 1
	./runall.sh 16 256 2 2 2 1
	./runall.sh 16 512 2 2 2 1

	./runall.sh 16 64 4 2 2 1
	./runall.sh 16 64 8 2 2 1
	./runall.sh 16 64 16 2 2 1

	./runall.sh 16 64 2 4 2 1
	./runall.sh 16 64 2 8 2 1

	./runall.sh 16 64 2 2 4 1
	./runall.sh 16 64 2 2 8 1

	./runall.sh 16 64 2 2 2 2
	./runall.sh 16 64 2 2 2 4