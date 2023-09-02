#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Function declaration
void Add_Task(void);
void Disp_Task(void);
void Remove();

//Global variables definition
int Task_Num = 0;//Number of tasks
char Task[100][100];//String to store tasks
int Task_Complete[100] = {0};//Tasks completed

int main()
{
    int option;
    while(1)
    {
        //Get option number from user
        printf("1)Add task\n2)View task\n3)Mark as Complete\n4)Remove task\n5)Exit\n\nSelect an option: ");
        scanf("%i",&option);
        if(option == 1)
        {//Add task
            printf("Enter Task Describtion: ");
            Add_Task();//Add task function
            system("cls");
            printf("Task Added Successfully!\n\n\n");
        }
        else if(option == 2)
        {//Display tasks
            system("cls");
            Disp_Task();//Display tasks fucntion
        }
        else if(option == 3)
        {//Mark task as completed
            Complete_Task();//Mark task as completed
        }
        else if(option == 4)
        {//remove task
            Remove();//Remove task function
        }
        else if(option == 5)//Exit program
            break;
        else
        {//Invalid input
            system("cls");
            printf("Enter Valid Input\n");
        }
    }
    system("cls");
    printf("Exiting Task Manager. Have a Despicable Day!!");
    return 0;
}

void Add_Task(void)
{
    getchar();
    //Get task description
    scanf("%[^\n]%*c",&Task[Task_Num++]);
}
void Disp_Task(void)
{
    if(!Task_Num)
    {//Task list empty
        printf("Task list empty");
    }
    else
    {
        //Get length of the longest task
        int Max_Task_Lenght = 0;
        for(int i = 0; i < Task_Num; i++)
        {
            if(strlen(Task[i]) > Max_Task_Lenght)
            Max_Task_Lenght = strlen(Task[i]);
        }
        if(Max_Task_Lenght < 16)
            Max_Task_Lenght = 16;

        //Display tasks
        printf("Current tasks:\n\n");
        //%-10s assigns 10 spaces to the right
        printf("%s | %*s | %s\n", "Task ID", -Max_Task_Lenght,"Task Description", "Status");
        //%*s assigns number of spaces equal to max task length
        //negative sigh in %-*s to print the space right to the sentence not to the left

        //Find minimum number of seperators to print
        int Space_Num = Max_Task_Lenght + 28;
        //Print the seperators
        if(Space_Num < 42)
            {
                for(int i = 0; i < 42; i++)
            printf("-");
            }
        else
        {
        for(int i = 0; i <= Space_Num; i++)
            printf("-");
        }

        printf("\n");
        for(int i =0; i < Task_Num; i++)
        {
            //Print each task sentence
             printf("  %-5d | %-*s | ", i + 1, (Max_Task_Lenght), Task[i]);
            if(Task_Complete[i])//Mark completed if true
                printf("  //Completed\n");
            else
            printf("Not Completed\n");
            if(Space_Num < 42)//Draw more seperators
            {
                for(int i = 0; i < 42; i++)
            printf("-");
            }
        else
        {
        for(int i = 0; i <= Space_Num; i++)
            printf("-");
        }
        printf("\n");
        }
    }
    printf("\n\n\n");
}
void Complete_Task(void)
{
    int Task_Complete_Number = 0;
    //Take task number to mark as completed
    printf("Enter number of the task you completed: ");
    scanf("%i",&Task_Complete_Number);
    if((Task_Complete_Number <= 0 || Task_Complete_Number > Task_Num))
    {//Check validity of task number
        system("cls");
        printf("Enter valid task number\n\n\n");
    }
    else
    {//Mark as completed
        Task_Complete[Task_Complete_Number - 1] = 1;
        system("cls");
        Disp_Task();

    }

}
void Remove(void)
{
    int Num = 0;
    printf("Enter number of task to remove: ");
    //Get task number to remove
    scanf("%i",&Num);
    if((Num <= 0 || Num > Task_Num))
    {//Check validity of task number

        system("cls");
        printf("Enter valid task number\n");
    }
    else
    {
        for (int i = Num; i < Task_Num; i++)
        {//Remove task
            strcpy(Task[i - 1], Task[i]);
            Task_Complete[i - 1] = Task_Complete[i];
        }
        Task_Complete[Task_Num - 1] = 0;//Unmark task as completed
        Task_Num--;
        system("cls");
        printf("Task Removed Successfully!\n\n\n");
    }
}

