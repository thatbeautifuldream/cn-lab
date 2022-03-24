// EXP-4 - CRC-CCITT Polynomial to obtain CRC Code
// CRC : Cyclic Redundancy Check - data error detection
// CCITT : Consultative Committee for International Telephony and Telegraphy

#include<stdio.h>
int a[100], b[100], i, j, len, k, count = 0;

//Generator Polynomial:g(x)=x^16+x^12+x^5+1

int gp[] = { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

int main()
{
  void div();
  printf("\nEnter the length of Data Frame :");
  scanf("%d", &len);
  printf("\nEnter the Message :");
  for (i = 0; i < len; i++)
    scanf("%d", &a[i]);

  //Append r (16) degree Zeros to Msg bits//

  for (i = 0; i < 16; i++)
    a[len++] = 0;
  //Xr.M(x)  (ie. Msg+16 Zeros)
  for (i = 0; i < len; i++)
    b[i] = a[i];
  //No of times to be divided ie. Message Length
  k = len - 16;
  div();
  for (i = 0; i < len; i++)
    b[i] = b[i] ^ a[i];		//MOD 2 Subtraction
  printf("\nData to be transmitted : ");
  for (i = 0; i < len; i++)
    printf("%2d", b[i]);

  printf("\n\nEnter the Reveived Data : ");
  for (i = 0; i < len; i++)
    scanf("%d", &a[i]);

  div();

  for (i = 0; i < len; i++)
    if (a[i] != 0)
    {
      printf("\nERROR in Recived Data");
      return 0;
    }
  printf("\nData Recived is ERROR FREE");
}

void div()
{
  for (i = 0; i < k; i++)
  {
    if (a[i] == gp[0])
    {
      for (j = i; j < 17 + i; j++)
        a[j] = a[j] ^ gp[count++];
    }
    count = 0;
  }
}