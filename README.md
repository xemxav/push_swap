# push_swap

## Key take away: 

This project gave me a good understanding of different sorting algorithm like insertion sort and was an introduction to algorithm complexity.

## Project description : 

### This project makes two executables :

- **push_swap**
- **checker** 

###### Push_swap:

it takes a list of different number form MININT to MAXINT a create a stack (A).

Then the programm needs to order it with the help of a second stack (B) and the following instruction 

	- sa: swap A: swap the first two elements on stack
	- sb: sawp B: swap the first two elements on stack
	- ss: do commands sa and sb at the same time
	- pb: push A to B: take the first element on A and move it to the beginning of B
	- pa: push B to A: take the first element on B and move it to the beginning of A
	- ra: rotate A: move all the elements on A and move them towards the beginning, moving the first element to the end
	- rb: rotate B: move all the elements on B and move them towards the beginning, moving the first element to the end
	- rr: do commands ra and rb at the same time
	- rra: reverse rotate A: move all the elements on A and move them towards the end, moving the last element to the beginning
	- rrb: reverse rotate B: move all the elements on B and move them towards the end, moving the last element to the beginning
	- rrr: do commands rra and rrb at the same time

It prints the instructions on stdout.

###### checker**:

It takes the same numbers as argument and reads on stdin the instructions given by push_swap. It determines if it is ordered or not.

With option -v on both **checker** and **push_swap**, it enables the visualisation of both stacks'evolution.

#### Usage :

```bash
make
export ARG=<random list of int between MININT and MAXINT>
./push_swap $ARG | ./checker $ARG
```

