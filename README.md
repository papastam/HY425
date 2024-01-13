# Computer Architecture _([HY425](https://www.csd.uoc.gr/~hy425/))_

During the course of Computer Architecture, we were assigned a total of 4 assignments, 2 of them were theoretical and the other 2 were programming assignments. 

For the 2 programming assignments, we were used the tool [gem5](http://www.gem5.org/Main_Page) to simulate a computer system and make serveral modifications to it. After the modifications, we had to run some benchmarks and compare the results.

## Assignment 1
The [first assignment](assignment1/HY425_Homework1.pdf) requres us to make some comparisons between some given benchmarks of different processors. Also, we needed to calculate improvement in the performance given some optimiaztions on the processors. Finally, we had to calculate the MTTF of a system given some parameters. 

The report of this assignment can be found [here](assignment1/report.pdf).

## Assignment 2
The [second assignment](assignment2/HY425_Homework2.pdf) provides us with a loop in assembly code and the latencies of each instrutcion. We were requested to make multiple modifications to the code like reordering the instructions, Hand-Unrolling the given loop, register renaming and calculate the CPI of each case in order to find the best one. Given a architecture using Resrvation Stations, we had to calculate the number of cycles needed to execute the loop. 

The report of this assignment can be found [here](assignment2/report.pdf).

## Assignment 3 (Programming Assignment 1)
For the [first programming assignment](assignment3/HY425_Homework3.pdf), we were given a system with a single core and we had to implement a GAg and a PAg branch predictor. After implementing the predictors and running some benchmarks for debugging purposes, we had to run benchmarks and compare the results of the system with the predictors and the system without them.

The files [GAgPredictor.cc](prog_assignment1/gem5/src/cpu/pred/GAgPredictor.cc) and [PAgPredictor.cc](prog_assignment1/gem5/src/cpu/pred/PAgPredictor.cc) can be found in the [prog_assignment1/gem5/src/cpu/pred](prog_assignment1/gem5/src/cpu/pred) directory.

The output of the benchmarks can be found in the [prog_assignment1/turnin](prog_assignment1/turnin) directory.

The report of this assignment can be found [here](prog_assignment1/report.pdf).

## Assignment 4 (Programming Assignment 2)
For the [second programming assignment](assignment4/HY425_Homework4.pdf), we were given a system with a single core and we had to execute benchmarks while changing the following parameters about the system:
- `LSQ_ENTRIES`: The number of entries in the Load/Store Queue
- `ROB_ENTRIES`: The number of entries in the Reorder Buffer
- `FUINT_NUM`: The number of simple Int Functional Units (ADD etc.)
- `FUCOM_NUM`: The number of complex Int Functional Units (MULT, DIV etc.) 
- `FUFP_NUM`: The number of Floating Point Functional Units (FADD, FMULT etc.)
- `FULS_NUM`: The number of Load/Store Functional Units

After running the benchmarks, we had to compare the results and find the best combination of the parameters.

All the benchmark statistics can be found in the [prog_assignment2/gem5/hy425](prog_assignment2/gem5/hy425) directory _(I executed 3 runs of benchmarks, each contained in their own folder)_.

The report of this assignment can be found [here](prog_assignment2/report.pdf).