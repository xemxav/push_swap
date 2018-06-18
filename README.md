# push_swap

This project makes two executables :
	- push_swap takes a list of different number form MININT to MAXINT a create a stack (A). Then the programm needs to order it with the help of a second stack (B) and the following instruction :
	sa: swap A: swap the first two elements on stack A
	sb: sawp B: swap the first two elements on stack B
	ss: do commands sa and sb at the same time
	pb: push A to B: take the first element on A and move it to the beginning of B
	pa: push B to A: take the first element on B and move it to the beginning of A
	ra: rotate A: move all the elements on A and move them towards the beginning, moving the first element to the end
	rb: rotate B: move all the elements on B and move them towards the beginning, moving the first element to the end
	rr: do commands ra and rb at the same time
	rra: reverse rotate A: move all the elements on A and move them towards the end, moving the last element to the beginning
	rrb: reverse rotate B: move all the elements on B and move them towards the end, moving the last element to the beginning
	rrr: do commands rra and rrb at the same time

	- checker takes the same numbers as argument and reads the instructions given by push_swap. It determines if it ordered or not.

I used an insertion sort for list of number bigger than 50.

With option -v on both checker and push_swap, it enables the visualisation of the evolution of both stacks. 

This project gave me a good understanding of different sorting algorithm and was an introduction to algorithm complexity.
