#include "RandMT.h"
unsigned long RandMT::state[n] = {0x0UL};
int RandMT::p = 0;
bool RandMT::init = false;
void RandMT::genState()
{ // generate new state vector
 for(int i=0; i<(n-m); ++i)
 state[i] = state[i + m] ^
 handle(state[i], state[i + 1]);

 for(int i=n-m; i<(n-1); ++i)
 state[i] = state[i + m - n] ^
 handle(state[i], state[i + 1]);
 state[n-1] = state[m - 1] ^
 handle(state[n - 1], state[0]);
 p = 0; // reset position
}
void RandMT::seed(unsigned long s)
{ // init by 32 bit seed
 state[0] = s & 0xFFFFFFFFUL; // for > 32 bit machines

 for(int i=1; i<n; ++i)
 {
 state[i] = 1812433253UL * (state[i - 1] ^
 (state[i - 1] >> 30)) + i;
 state[i] &= 0xFFFFFFFFUL;//for > 32 bit machines
 }

 p = n; // force genState() to be called
 // for next random number
}
void RandMT::seed(const unsigned long* arr, int size)
{ // init by array
 seed(19650218UL);
 int i=1, j=0;

 for(int k=((n>size)?n:size); k; --k)
 {
 state[i] = (state[i] ^ ((state[i - 1] ^
 (state[i - 1] >> 30)) * 1664525UL))
 + arr[j] + j; // non linear

 state[i] &= 0xFFFFFFFFUL;//for > 32 bit machines

 ++j;
 j %= size;

 if((++i)==n)
 {
 state[0] = state[n-1];
 i = 1;
 }
 }

 for(int k=n-1; k; --k)
 {
 state[i] = (state[i] ^ ((state[i - 1] ^
 (state[i - 1] >> 30)) * 1566083941UL)) - i;

 state[i] &= 0xFFFFFFFFUL;//for > 32 bit machines

 if((++i)==n)
 {
 state[0] = state[n-1];
 i=1;
 }
 }

 state[0] = 0x80000000UL;

 p = n; // force genState() to be called for next
       // random number
}
