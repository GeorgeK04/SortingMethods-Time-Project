#ifndef RANDMT_H
#define RANDMT_H
class RandMT
{
 protected:
 unsigned long rand_int32();
 // generate 32 bit random integer
 private:
 static const int n = 624, m = 397;
 static unsigned long state[n];
 // state vector array
 static int p; // position in state array
 static bool init;
 // true if init function is called
 unsigned long handle(unsigned long, unsigned long);
 // used by genState()
 void genState(); // generate new state
 RandMT(const RandMT&);
 // copy constructor not defined
 void operator=(const RandMT&);
 // assignment operator not defined

 public:
 RandMT()
 {
 if(!init)
 seed(5489UL);
 init = true;
 }
 RandMT(unsigned long s)
 {
 seed(s);
 init = true;
 }
 RandMT(const unsigned long* arr, int size)
 {
 seed(arr, size);
 init = true;
 }
 void seed(unsigned long);
 // seed with 32 bit integer
 void seed(const unsigned long*, int size);
 // seed with array

 unsigned long operator()()
 {
 return rand_int32();
 }
 virtual ~RandMT()
 {}
};
// inline for speed, must therefore reside
// in header file
inline unsigned long RandMT::handle(unsigned long u, unsigned long v)
{
 return
 (((u & 0x80000000UL) | (v & 0x7FFFFFFFUL)) >> 1)
 ^ ((v & 1UL) * 0x9908B0DFUL);
}
inline unsigned long RandMT::rand_int32()
{ // generate 32 bit random int
 if(p == n)
 genState(); // new state vector needed
 unsigned long x = state[p++];
 x ^= (x >> 11);
 x ^= (x << 7) & 0x9D2C5680UL;
 x ^= (x << 15) & 0xEFC60000UL;
 return x ^ (x >> 18);
}
#endif // RANDMT_H

