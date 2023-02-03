# LA2

## Assignment Instructions
A multi-level priority queue is a queue data structure in which every item includes two pieces of information: "data" and "priority".

While "data" could be of any type, the "priority" of each item is a constant value that is initialized at the time that the item is created and is assigned based on the item's precedence order in the system compared to other items; i.e. once an item is created, its "priority" will not be changed. Items' priorities are identified by an integer in the range [1, 10] where 1 shows the lowest precedence order and 10 is assigned to items with the highest precedence order in the system.

When entering the queue, each item is inserted into the queue that is associated with its "priority" value. Items with the same priority are served on a FIFO basis but items of the lower priority queues are only served if all the queues at the higher levels of priority are empty. Implement this ADT as specified below.

**Part 1:**

Implement the Queue ADT as a linked structure and use it to implement the multi-level priority queue in Part 2.

**Part 2:**

Use the Queue ADT implemented in Part 1 to implement the multi-level priority queue ADT. Use an array-based implementation to illustrate the different queue levels.

**Part 3:**

Analyze the time and space complexity of your implementation.

## Submission Instructions:

- Do not zip your files. Submit each file as an individual attachment.
- Write your answers to the third part in a separate document and submit it in PDF format.
