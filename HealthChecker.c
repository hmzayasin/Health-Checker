/*
 =================================================================================================
 Name        : HealthCheck.c
 Author      : Hamza Yasin
 Description : BMI Calculator, Blood Pressure Assesment and Cardiac Risk Score Assessment

 =================================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

// Initalise Functions
void BMI_Calculation();
void Blood_Pressure();
void Cardiac_Risk_Score();

// Initalise Variables
int user_input = 0;

int main(void){

	printf("Welcome to my Health Check Program.\n");
	while (user_input != 4)
	{
		//Asks the user for input on what they want assessed
		printf("\n'1' For BMI\n");
		printf("'2' for Blood Pressure Assessment\n");
		printf("'3' for Cardiac Risk Score Assesment\n");
		printf("'4' to quit\n");

		if (scanf("%d", &user_input) != 1 || (user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4)){
			printf("\nInvalid Input! Either '1', '2', '3' or '4'.\n");
			while (getchar() != '\n'); 
			continue;
		}

		printf("\n");

		// if statements to match what the user inputed, if a match is found then it goes into asking for input
		// and calls the function
		if (user_input == 1){
			
			// call to the BMI function and we use the 2 inputs we just recieved as parameters
			BMI_Calculation();
		}

		// 2nd if statment
		else if (user_input == 2){

			//we call the blood pressure function with the inputs we just recieved as parameters
			Blood_Pressure();
		}

		//3rd if statement
		else if (user_input == 3){

			// call the Cardiac Risk Score function with the input we just got as parameters
			Cardiac_Risk_Score();
		}

		else if(user_input == 4)
		{
			printf("Thank you for using Health Check.\n");
			break;
		}

		// error handling, if the input is not 1, 2 or 3 then its invalid.
		else{
			printf("Invalid Input! Either '1', '2', '3' or '4'.\n");
		
		}
	}
}


/* We use a formula for BMI and calculate it using the weight and height inputs we recieved
 * we then do a few if statements that state if the user is underweight, overweight, normal
 * weight etc.
 */
void BMI_Calculation(){

	double BMI = 0, weight = 0, height = 0;

		// asking for input
		printf("Weight in KG: ");
		
		if ((scanf("%lf", &weight) != 1) || weight <= 0){ //error handling for if input is not integer or float
			printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
			while (getchar() != '\n');
			return; // ends the whole code and marks it as an error
		}


		printf("Height in Meters: ");
		
		if ((scanf("%lf", &height) != 1) || height <= 0){
			printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
			while (getchar() != '\n'); 
			return;
		}

		printf("\n");

	BMI = weight / pow(height, 2);
	printf("%.1lf \n", BMI); // we round it to 1 decimal place
	

	if (BMI < 18.5){
		printf("You are Underweight.\n");
		
	}

	else if (BMI > 18.5 && BMI < 24.9){
		printf("You are of Normal weight.\n");
		
	}

	else if (BMI > 25 && BMI < 29.9){
		printf("You are Overweight.\n");
		
	}

	else if (BMI > 30){
		printf("You are Obese.\n");
		
	}
}


/* In this function we do if statements that categorize what blood pressure the user has
 * according to their average systolic and diastolic blood pressure
 */
void Blood_Pressure(){

	double avg_sys = 0, avg_dia = 0, total_sys = 0, total_dia = 0;
	float Systolic[5] = {0};
	float Diastolic[5] = {0};

			// ask for 5 Systolic Measures to get an average
		for (int i = 0; i < 5; i++){
			printf("Enter Systolic Measure #%d (in mmHg): ", i + 1);
			
			if ((scanf("%f", &Systolic[i]) != 1) || Systolic[i] <= 0){     //we use an array to store input
				printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
				while (getchar() != '\n'); 
				return;
			}

			printf("Enter Diastolic Measure #%d (in mmHg): ", i + 1);
			
			if ((scanf("%f", &Diastolic[i]) != 1) || Diastolic[i] <= 0) {    //we use an array to store input
				printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
				while (getchar() != '\n'); 
				return;

			}

			printf("\n");
			

			total_sys += Systolic[i]; // calculate the sum of the 5 inputs
			total_dia += Diastolic[i];
		}




		avg_sys = total_sys/5;
								// get average of both systolic and diastolic
		avg_dia = total_dia/5;

	if (avg_sys >= 140 || avg_dia >= 90){
		printf("High Blood Pressure.\n");
		
	}

	else if ((avg_sys >= 120 && avg_sys < 140) || (avg_dia >= 80 && avg_dia < 90)) {
		printf("Pre-high Blood Pressure.\n");
		
	}

	else if ((avg_sys >= 90 && avg_sys < 120) || (avg_dia >= 60 && avg_dia < 80)){
		printf("Ideal Blood Pressure.\n");
		
	}

	else if (avg_sys < 90 && avg_dia < 60){
		printf("Low Blood Pressure.\n");
		
	}

}



/* In this function we ask for more input such as what gender, do they have diabetes and are they
 * a smoker. Afterwards i did 2 if statements, one for Male and one for Female. I then did if
 * Statements for age, and then inside of those If statements I then did a lot of if statements
 * that went through if they smoked and had diabetes, smoked and didnt
 * have diabetes, didnt have diabetes and smoked, didnt have diabetes and didnt smoke. i then
 * did if statements inside of those if statements and printed out the danger level according
 * to their SBP and Cholestrol levels
 *
 * If the person inputted the wrong input for gender, diabetic or smoker then it would just print
 * out an error message.
 */
void Cardiac_Risk_Score(){

	double SBP = 0, chol = 0;
    char gender;
    int diabetic = 0, smoker = 0, age = 0;

    //gather input
	printf("Enter user's Systolic Blood Pressure (in mmHg):\n");
		
	if ((scanf("%lf", &SBP) != 1) || SBP <= 0){
		printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
		while (getchar() != '\n'); 
		return;
	}

	printf("Enter your Cholesterol Level:\n");
		
	if ((scanf("%lf", &chol) != 1) || chol <= 0){
		printf("\nError, Input has to be an Integer or a Float and Greater than 0.\n");
		while (getchar() != '\n'); 
		return;
	}

	printf("Enter your Age (Minimum Age of 30):\n");
		
	if ((scanf("%d", &age) != 1) || age < 30)
	{
		printf("\nError, Input has to be Integer and Above 30\n");
		while (getchar() != '\n'); // to clear buffer
		return;
	}


	printf("What is your gender? (M for Male, F for Female)\n"); 
	
	scanf(" %c", &gender);

	if (gender != 'M' && gender!= 'F'){
		printf("\nInput has to be either 'M' or 'F'\n");
		while (getchar() != '\n'); 
		return;
	}

	printf("Do you have Diabetes? (1 for True, 2 for False)\n");
	
	scanf("%d", &diabetic);

	if (diabetic != 1 && diabetic != 2){
		printf("\nInput Has to be either 1 or 2\n");
		while (getchar() != '\n'); 
		return;
	}

	printf("Are you a smoker? (1 for True, 2 for False)\n");
	
	scanf("%d", &smoker);

	if (smoker != 1 && smoker != 2){
		printf("\nInput Has to be either 1 or 2\n");
		while (getchar() != '\n'); 
		return;
	}

	printf("\n");
	

	if (gender == 'M'){
		if (age >= 80){
			printf("Very High\n");
			
		}

		else if (age < 40){
			printf("Low\n");
			
		}

		else if (age >= 70 && age <= 79){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 1 && smoker == 1) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 140){
					printf("Very High\n");
					
				}

				else{
					printf("High\n");
					
				}
			}

			else if (diabetic == 2 && smoker == 2){
				if (SBP >= 140){
					printf("High\n");
					
				}

				else{
					printf("Moderate-high\n");
					
				}
			}
		}

		else if (age >= 60 && age <= 69){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 140){
					printf("High\n");
					
				}

				else if (SBP < 140 && chol < 5.2){
					printf("Moderate\n");
					
				}

				else{
					printf("Moderate-High\n");
					
				}
			}

			else if (diabetic == 1 && smoker == 1){
				if (SBP >= 180){
					printf("Very High\n");
					
				}

				else if ((SBP >= 160 && SBP < 180) && chol >= 6.5){
					printf("Very High\n");
					
				}

				else if(SBP < 140){
					printf("Moderate-High\n");
					
				}

				else{
					printf("High\n");
					
				}
			}

			else if (diabetic == 2 && smoker == 2){
				if (SBP >= 140){
					printf("Moderate-High\n");
					
				}

				else{
					printf("Moderate\n");
					
				}
			}
		}

		else if (age >= 50 && age <= 59){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 140){
					printf("Moderate\n");
					
				}

				else{
					printf("Mild\n");
					
				}
			}

			else if (diabetic == 1 && smoker == 1){
				if (SBP >= 160){
					printf("Moderate-High\n");
					
				}

				else if (SBP >= 140 && SBP < 160){
					printf("Moderate\n");
					
				}

				else if ((SBP < 140) && (chol > 5.2 && chol <= 7.7)){
					printf("Moderate\n");
					
				}

				else{
					printf("Mild\n");
					
				}
			}

			else if (diabetic == 2 && smoker == 2){
				if (SBP >= 180 && chol >= 5.2){
					printf("Moderate\n");
					
				}

				else{
					printf("Mild\n");
					
				}

			}
		}

		else if (age >= 40 && age <= 49){
			if (diabetic == 1 && smoker == 2){
				if (SBP >= 180){
					printf("Mild\n");
					
				}

				else if ((SBP >= 160 && SBP < 180) && chol >= 6.5){
					printf("Mild\n");
					
				}

				else{
					printf("Low\n");
					
				}
			}

			else if (diabetic == 1 && smoker == 1){
				if (SBP >= 140){
					printf("Mild\n");
					
				}

				else{
					printf("Low\n");
					
				}
			}

			else if (diabetic == 2 && smoker == 2){
				printf("Low\n");
				
			}

			else if (diabetic == 2 && smoker == 1){
				if (SBP >= 180 && chol > 5.2){
					printf("Mild\n");
					
				}

				else if((SBP >= 160 && SBP < 180) && chol >= 6.5){
					printf("Mild\n");

				}

				else{
					printf("Low\n");
					
				}
			}
		}

	}

	else if (gender == 'F'){
		if (age >= 80){
			printf("Very High\n");
			
		}

		else if (age >= 30 && age <= 49){
			printf("Low\n");
			
		}

		else if (age >= 70 && age <= 79){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 180){
					printf("Very High\n");
					
				}

				else{
					printf("High\n");
					
				}
			}

			else if (diabetic == 1 && smoker == 1){
				printf("Very High\n");
				
			}

			else if (diabetic == 2 && smoker == 2){
				if (SBP >= 180){
					printf("High\n");
					
				}

				else{
					printf("Moderate-High\n");
					
				}
			}
		}

		else if (age >= 60 && age <= 69){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 180){
					printf("High\n");
					
				}

				else{
					printf("Moderate\n");
					
				}
			}

			else if (diabetic == 1 && smoker == 1){
				if (SBP >= 180){
					printf("High\n");
					
				}

				else{
					printf("Moderate-High\n");
					
				}
			}

			else if (diabetic == 2 && smoker == 2){
				if (SBP >= 180){
					printf("Moderate\n");
					
				}

				else{
					printf("Mild\n");
					
				}
			}
		}

		else if (age >= 50 && age <= 59){
			if ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)){
				if (SBP >= 180){
					printf("Moderate\n");
				}

				else{
					printf("Mild\n");
				}
			}

			else if (diabetic == 1 && smoker == 1){
				if (SBP >= 180){
					printf("Moderate-High\n");
				}

				else{
					printf("Moderate\n");
				}
			}

			else if (diabetic == 2 && smoker == 2){
				printf("Mild\n");
			}
		}


	}
}

