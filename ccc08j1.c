include <stdio.h>


int
main()
{
  double w, h;
  scanf("%lf%lf", &w, &h);
  double BMI = w / (h * h);
  if (BMI < 18.5) 
    printf("Underweight\n");
  else if (BMI > 25)
    printf("Overweight\n");
  else
    printf("Normal weight\n");
  return 0;
}
