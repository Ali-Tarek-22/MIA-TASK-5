#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function declaration
float weightedAverage(double value1, double accuracy1, double value2, double accuracy2);
float Kal(double Value1, double Accuracy1, double Value2, double Accuracy2);



int main()
{
    // Sample sensor measurements and accuracies
    //Sensor one
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    double Accuracy1 = 0.79;

    //Sensor two
    float bno55[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    double Accuracy2 = 0.92; // 92%

    //Find size of the set of data
    int Size = sizeof(mpu6050) / sizeof(mpu6050[0]);

    //Create an array to store corrected data
    float Improved_Value[10];

    //Fill the array with the corrected data
    for(int i = 0; i < Size; i++)

    {
    //Call weightedAverage function
        Improved_Value[i] = weightedAverage(mpu6050[i], Accuracy1, bno55[i], Accuracy2);
    }

    printf("mpu6050 sensor data:\n{");
    for(int i = 0; i < Size - 1; i++)
        printf("%.2f,",mpu6050[i]);

    printf("%.2f}\n\n\n",mpu6050[Size - 1]);


    printf("bno55 sensor data:\n{");
    for(int i = 0; i < Size - 1; i++)
        printf("%.2f,",bno55[i]);

    printf("%.2f}\n\n\n",bno55[Size - 1]);


    //Display the corrected data
    printf("More accurate data (Weighted value method):\n{");
    for(int i = 0; i < Size - 1; i++)
        printf("%.2f,",Improved_Value[i]);

    printf("%.2f}\n\n",Improved_Value[Size - 1]);



    for(int i = 1; i < Size; i++)
    {
        //Call Kalman function
        Improved_Value[i] = Kal(mpu6050[i], Accuracy1, bno55[i], Accuracy2);
    }
    //Display the corrected data
    printf("More accurate data (Kalman filter method):\n{");
    for(int i = 0; i < Size - 1; i++)
        printf("%.2f,",Improved_Value[i]);

    printf("%.2f}\n",Improved_Value[Size - 1]);
    return 0;
}

//weightedAverage function
float weightedAverage(double Value1, double Accuracy1, double Value2, double Accuracy2)
{
    //Make the data weighted corresponding to its accuracy
    float Weight1 = Value1 * Accuracy1 / (Accuracy1 + Accuracy2);
    float Weight2 = Value2 * Accuracy2 / (Accuracy1 + Accuracy2);

    //Add the two weighted values
    float Improved_Value = Weight1 + Weight2;

    //Return the improved value value
    return Improved_Value;
}



//Kalman function
float Kal(double Value1, double Accuracy1, double Value2, double Accuracy2)
{
    //Calculate the Kalman gain
    float k = Accuracy1 / (Accuracy1 + Accuracy2);

    //Calculate the more accurate value
    float Improved_Value = Value1 + k * (Value2 - Value1);

    //Return the improved value
    return Improved_Value;
}
