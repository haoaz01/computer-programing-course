#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculation(FILE *employee_salary)
{
	char name[200];
    char NIC[12];
    char category[2];
    unsigned int total_hours;
	int hao =1;

    do {
        float gross_pay, overt_pay, net_pay;
        char cate[2];
        int hour_work;
        int cE[3] = {10, 12, 15};
        int cM[2] = {20, 25};
    	printf("Name: ");
        gets(name);
        printf("NIC: ");
        gets(NIC);
        printf("Category: ");
        scanf("%s", &cate);
        printf("Total hours: ");
        scanf("%d", &hour_work);

        char firstCate[2];
        char secondCate[2];
        strncpy(firstCate, cate, 1);
        firstCate[1] = '\0';
        strncpy(secondCate, cate + 1, 1);
        secondCate[1] = '\0';

        int NsecondCate = atoi(secondCate);
        NsecondCate -= 1;
        int lenCate = strlen(cate);
        
        if (strcmp(cate, "E1") == 0 || strcmp(cate, "E2") == 0 || strcmp(cate, "E3") == 0 || strcmp(cate, "M1") == 0 ||strcmp(cate, "M2") == 0 )
        {
		
        
        if (hour_work<= 60)
        {
		
		if (strcmp(cate, "E1") == 0 || strcmp(cate, "E2") == 0 || strcmp(cate, "E3") == 0 )
			{ if (hour_work <= 40)
			{
                gross_pay = hour_work * cE[NsecondCate];
                overt_pay = 0;
            } else if (hour_work > 40) {
                gross_pay = 40 * cE[NsecondCate];
                overt_pay = (hour_work - 40) * 1.5 * cE[NsecondCate];
            }
	        } else 	if (strcmp(cate, "M1") == 0 ||strcmp(cate, "M2") == 0 ) 
			{
	            if (hour_work <= 40 ) {
	                gross_pay = hour_work  * cE[NsecondCate];
	                overt_pay = 0;
	            }
	            else
				{
	            	gross_pay = 40 * cM[NsecondCate];
	            	overt_pay = 0;

				}
			}        
		net_pay = gross_pay + overt_pay;

        for (int i ;i < hao; i++)
        {
        printf("\t\t\t ZEN ICT SOLUTIONS\n");
     	printf("============================================================\n");
		}
        if (hour_work <= 60)
        {
        printf("\nName: %s\n", name);
		printf("NIC: %s\n", NIC);
		printf("Category: %s\n", cate);
		printf("Total Hours: %d\n", hour_work);
        printf("Gross Pay: $ %.2f\n", gross_pay);
        printf("Overtime Pay: $ %.2f\n", overt_pay);
      	printf("Net Pay: $ %.2f\n", net_pay);
		}
		else 
		{			            
		printf("\nINPUT NOT VALID!!\n");
		}

      	if (employee_salary != NULL && hour_work <=60)
		{

		  
		fprintf(employee_salary,"\nName: %s\n", name);
		fprintf(employee_salary,"NIC: %s\n", NIC);
		fprintf(employee_salary,"Category: %s\n", cate);
		fprintf(employee_salary,"Total Hours: %d\n", hour_work);
		fprintf(employee_salary,"Gross Pay: $ %.2f\n", gross_pay);
		fprintf(employee_salary,"Overtime Pay: $ %.2f\n", overt_pay);
		fprintf(employee_salary,"Net Pay: $ %.2f\n", net_pay);
		}
		}
        else 
		{
            printf("\nINPUT NOT VALID!!\n");
        }
		}
		else
		{
			printf("\nINPUT NOT VALID!!\n");

		}
        char choice;
        
        printf("\nContinue (Y/N)?: " ); scanf(" %c", &choice);
        printf("\n");

        if (choice != 'Y' && choice != 'y') 
		{
            break;
        }
        getchar();
    	} while (1);

}


int main() 
{
    FILE *employee_salary;
    employee_salary = fopen("employees.dat", "w");
    fprintf(employee_salary, "\t\tZEN ICT SOLUTIONS SDN BHD\n");
    fprintf(employee_salary, "============================================================\n");
	calculation(employee_salary);	 
	fclose(employee_salary);  
	return 0;
}
