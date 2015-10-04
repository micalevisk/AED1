#include <stdio.h>
#include <stdbool.h>


bool condicional(bool x, bool y){ // x -> y
  return ( (x && y) || (!x && y) || (!x == !y) );            
}


bool biCondicional(bool x, bool y){ // x <-> y
  return (x == y);
}


int main(){

  bool P = true; 
  bool Q = false; 
  bool R = true;
  bool S = true;
  bool T = true;

  bool a = P  || (Q && R);                      // P V (Q ∧ R)
  bool b = !R || S;                             // ¬R V S
  bool c = condicional(S, !T);                  // S → ¬T
                                                // -----------
  bool conclusao = condicional(a && b && c, P); // T → P

  bool s1 = ( (Q||P) && (R||P) ) == a;
  bool s2 = condicional(!S, !R);
  bool s3 = condicional(!R, P)   == (R||P);

  
  //  printf(" %d \n", condicional(P,Q)? 1:0);

  printf(" P \t Q \n");
  printf("-------------\n");
  int i;
  for(i=1; i < 5; i++)
    printf(" V\t| F \n");

}
