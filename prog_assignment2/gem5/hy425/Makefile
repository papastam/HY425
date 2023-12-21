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

# The best values of each parameter are:
# (The parentheses indicate the values preformed the same as the previous one, therefore they will not be tested)
# 
# LSQ_ENTRIES: 128
# ROB_ENTRIES: 128, 256, (512)
# FUINT_NUM: 4, 8, (16)
# FUCOM_NUM: 4, (8)
# FUFP_NUM: 2, 4, (8)
# FULS_NUM: 2, 4

# Second step:
# Run tests with the combinations of the best values of each parameter.
second_step:
	# 128 LSQ_ENTRIES
	./runall.sh 128 128 4 4 2 2
	./runall.sh 128 128 4 4 2 4
	
	# 4 FUFP_NUM
	./runall.sh 128 128 4 4 4 2
	./runall.sh 128 128 4 4 4 4

	# 8 FUINT_NUM
	./runall.sh 128 128 8 4 2 2
	./runall.sh 128 128 8 4 2 4
	./runall.sh 128 128 8 4 4 2
	./runall.sh 128 128 8 4 4 4

	# 256 ROB_ENTRIES
	./runall.sh 128 256 4 4 2 2
	./runall.sh 128 256 4 4 2 4

	# 4 FUFP_NUM
	./runall.sh 128 256 4 4 4 2
	./runall.sh 128 256 4 4 4 4

	# 8 FUINT_NUM
	./runall.sh 128 256 8 4 2 2	
	./runall.sh 128 256 8 4 2 4
	./runall.sh 128 256 8 4 4 2
	./runall.sh 128 256 8 4 4 4

# Explore with the values going up to todays values of each parameter.
mip_exploration:
	./runall.sh 128 128 4 2 2 1
	./runall.sh 128 128 4 2 2 3

	./runall.sh 128 128 4 2 3 1
	./runall.sh 128 128 4 2 3 3

	# Changed the value of FUINT_NUM to 5
	./runall.sh 128 128 5 2 2 1
	./runall.sh 128 128 5 2 2 3

	./runall.sh 128 128 5 2 3 1
	./runall.sh 128 128 5 2 3 3

	# Changed the value of ROB_ENTRIES to 384
	./runall.sh 128 384 4 2 2 1
	./runall.sh 128 384 4 2 2 3

	./runall.sh 128 384 4 2 3 1
	./runall.sh 128 384 4 2 3 3

	# Changed the value of FUINT_NUM to 5
	./runall.sh 128 384 5 2 2 1
	./runall.sh 128 384 5 2 2 3

	./runall.sh 128 384 5 2 3 1
	./runall.sh 128 384 5 2 3 3

	# Changed the value of LSQ_ENTRIES to 64
	./runall.sh 64 384 5 2 2 1
	./runall.sh 64 384 5 2 2 3

	./runall.sh 64 384 5 2 3 1
	./runall.sh 64 384 5 2 3 3

	# Changed the value of FUINT_NUM to 5
	./runall.sh 64 384 5 2 2 1
	./runall.sh 64 384 5 2 2 3

	./runall.sh 64 384 5 2 3 1
	./runall.sh 64 384 5 2 3 3

	# Changed the value of ROB_ENTRIES to 384
	./runall.sh 64 384 5 2 2 1
	./runall.sh 64 384 5 2 2 3

	./runall.sh 64 384 5 2 3 1
	./runall.sh 64 384 5 2 3 3

	# Changed the value of FUINT_NUM to 5
	./runall.sh 64 384 5 2 2 1
	./runall.sh 64 384 5 2 2 3

	./runall.sh 64 384 5 2 3 1
	./runall.sh 64 384 5 2 3 3