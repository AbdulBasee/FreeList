#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {

   
    head = inRAM;
    inRAM[0] = size - 2;
    
    helper1 = inRAM;
    
}

long int*
freeList::reserve_space( int size ) {

    long int* loc = head;

    int rem = head[0] - size - 2;

    loc[0] = size;
    loc[1] = 123456789; // magic number

    head = head + size + 2;

    head[0] = rem;
    head[1] = 0;
    
  
    //loc = loc + size;
    return loc;

                      
}

void
freeList::free_space( long int* location ) {
     long int* loc = location;

    //loc = loc + loc[0] + 2;
    loc[1] = loc[0];
    location[1] = loc[0] + 2;

}

void
freeList::coalesce_forward() {
	 long int* ref1 = helper1;

 	 long int* ref2 = ref1 + 2 + ref1[0];


  
 	 long int* next = (long int*)ref1[1];
  


 	 cout << head[0];
 	 while(ref1[1] != 0){

     		 if(ref2[1] == next[0] ){
       		 head[0] = head[0] + ref2[0];

     	 }
      
     	 ref1 = next;
 	 }


}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
