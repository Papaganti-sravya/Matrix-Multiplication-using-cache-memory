# Matrix-Multiplication-using-cache-memory
Final Project report
Introduction:
           Performing matrix multiplication using 
                     Cache memory 
                     Registers
                     Normal matrix multiplication
           Compare the average time of these methods and conclude the optimised matrix.

Background:
   The  areas we should know about this project are
1.	Cache memory locality:
                   Temporal locality:  Referred to the data items that are used frequently
                   Spatial locality : Referred to address that is located near by in cache memory
2.	Tags in cache memory:
              Tags are used to specify the data
               Tags along with the index value allow use to find the exact data
3.	Cache Blocking:
            Since the entire matrix may not fix into the cache memory, we break the entire matrix into blocks and do the calculation
4.	Hit rate/ miss rate:
      Hit rate is used to determine if the data is present in the cache memory 
      Miss rate is used to determine if the data is not present in the cache memory
5.	Registers
         Since the register are in cpu use this method to calculate the matrix multiplication and expect it to be fastest among all.
         

Approach:
Cache memory:
    Since the cache memory is small in l1 cache we diving the entire matrix into chunks of matrix(blocks), the block size is the size that we want to divide the matrix into, and that block of matrix is send to the l1 cache memory and we could performs the calculations there.


How to calculate cache miss and cache hit ratio:
              Miss ratio =  1- hit ratio.  (or)
              Hit ratio = 1 – Miss ratio.   (or)
              Miss – Hit = 1

Register blocking:
        Problem with register blocking:
	The cpu is not fully utilized because of the memory bound.
	When the processor loads a cache line from the main memory into L1 cache, It loads the scalar value from cache line one at a time.
	While scanning the matrix and  use a single scalar from every cache line we load, by the time we finish scanning the last value there may be a chance that the memory has already flushed from the cache memory.

Solution 
        Since the problem is not utilising the memory to the fullest we resolve this like:
        Placing the dummy values in the size of the memory we took in register, So now we are sure that the register has the matrix of given size has data.
        When we enter into the algorithm we replace the dummy values with the actually values and perform the calculation so the advantage is, we don’t waste the memory and also we perform the calculation simultaneously.  
		


