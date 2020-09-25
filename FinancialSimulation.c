#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

//Define a basic "person" struct for the simulation
struct financialIdentity {
	double savings;
	double checkings;
	double debt;
	double loan;
	int yearsWithDebt;
	int yearsRented;
	double debtPaid;
	bool ownsHouse;
	char* fileName;
};

//Declare headers
void savingsPlacement(struct financialIdentity *person, double interestRate);
void debt(struct financialIdentity *person, double interestRate, double addlPay);
void rent(struct financialIdentity *person, double rentAmt);
void house(struct financialIdentity *person, double housePrice, double interestRate, double mortgageTerm);
int* simulate(struct financialIdentity *person, double yearlySalary, bool financiallyLiterate);


void savingsPlacement(struct financialIdentity *person, double interestRate)
//compound savings by appropriate IR
{
	person->savings = person->savings * (1.0 + interestRate);
}

void debt(struct financialIdentity *person, double interestRate, double addlPay)
//simulates one year of having debt
{
	double minimumPaymentPercent = 0.03; //dictated by our ficticious company
	//interate years w debt, IF person has debt
	if(person->debt > 0.0)
	{ person->yearsWithDebt++; }
	//Monthly calculation
	for(int m = 1; m <= 12; m++){
		if(person->debt > 0.0){
			double payment = (person->debt * minimumPaymentPercent) + addlPay;
			if(payment <= person->checkings){
				person->checkings -= payment;
			}
			else{
				person->savings -= (payment - person->checkings);
				person->checkings = 0;
			}
			person->debt -= payment;
			person->debtPaid += payment;
		}else{
			//when person pays debt off DURING one year
			///OR stops loop from running again
			person->debt = 0.0;
			break;
		}
	} //end year
	//compound debt, yearly
	person->debt *= 1.20;
}

void rent(struct financialIdentity *person, double rentAmt)
{
	//increment years person has rented
	person->yearsRented++;
	//take available money out of checking, use savings if nessesary
	if (person->checkings >= rentAmt){
		person->checkings -= rentAmt;
	} else {
		person->savings -= (rentAmt - person->checkings);
		person->checkings = 0;
	}
}

void house(struct financialIdentity *person, double housePrice, double interestRate, double mortgageTerm)
{
	//Calculate monthly mortgage payment
	interestRate = interestRate/12;
	double p = pow(1+interestRate, 360); //Number of payments is 360
	double discountFactor = (p - 1) / (interestRate * p );
	double monthlyPayment = person->loan / discountFactor;

	//Simulate payment each month of 1 year
	for (int i = 0; i < 12; i++){
		//remaining balance of the loan is greater than the monthly payment
		if (person-> loan >= monthlyPayment) {
			//add interest to loan
			person->loan += person->loan * interestRate;
			if (monthlyPayment <= person->checkings) {
				person->checkings -= monthlyPayment;
				person->loan -= monthlyPayment;
			} else {
				person->savings -= (monthlyPayment - person->checkings);
				person->checkings = 0;
				person->loan -= monthlyPayment;
			}
			//when loan balance is <= month
		} else {
			if (person->loan <= person->checkings){
				person->checkings -= person->loan;
				person->loan = 0;
			} else {
				person->savings -= (person->loan - person->checkings);
				person->checkings = 0;
				person->loan = 0;
			}
		}
	}//end year cycle

}

int* simulate(struct financialIdentity *person, double yearlySalary, bool financiallyLiterate)
{
	//set up simulation, using the given constants
	int* wealthAtYear = (int*)malloc(41 * sizeof(int)); //create an array with 41 slots
	wealthAtYear[0] = -24100;
	int housePrice = 175000;
	double rentAmt = 850;
	double savingsIR, loanIR, addtlPay;
	if (financiallyLiterate){
		savingsIR = .07;
		loanIR = .045;
		addtlPay = 15.0;
	} else { //not financially literate
		savingsIR = .01;
		loanIR = .05;
		addtlPay = 1.0;
	}

	//open a FILE for simulation results
	FILE* outputF = fopen(person->fileName, "w");
	if (!financiallyLiterate){  //create file header
		fprintf(outputF, "NON-"); }
	fprintf(outputF, "FINANCIALLY LITERATE SIMULATION\nStart simulation with %d\n", wealthAtYear[0]);

	//YEARLY SIMULATION
	for (int y = 1; y < 41; y++){
		//INCOME ALLOCATION
		//allocate accordingly
		person->savings += yearlySalary*.20;
		person->checkings += yearlySalary*.30;
		savingsPlacement(person, savingsIR);
		debt(person, .03, addtlPay);
		//HOUSEING CHOICES
		//if person has not yet purchased a house
		if (!person->ownsHouse) {
			if (financiallyLiterate) {
				if (person->savings >= housePrice*.20) {
					person->savings -= housePrice*.20;
					person->ownsHouse = true;
					housePrice *= .80;
				}
			} else { // IF nfl
				if (person->savings >= housePrice*.05){
					person->savings -= housePrice*.05;
					person->ownsHouse = true;
					housePrice *= .95;
				}
			}
		}
		//deals with housing expenses
		if (!person->ownsHouse){
			rent(person, rentAmt);
		} else { // person owns a house
			house(person, housePrice, loanIR, y);
		}

		//Record wealth at year y, output to file
		wealthAtYear[y] = (int)(person->savings + person->checkings - person->debt - person->loan);
		fprintf(outputF, "wealth at year %d: %d\n", y, wealthAtYear[y]);
	}
	return wealthAtYear;
}

int main(int argc, char* *argv){
	FILE* personFilePtr;
	bool isFL = false;
	int isFLnum = 0;
	//define variables for new strut
	int salary;
	double savings;
	double checkings;
	double debt;
	double loan;
	int yearsWithDebt;
	int yearsRented;
	double debtPaid;
	char* fileOutName;

	//run the simulation based on data from each command line arguement file
	for (int i = 1; i < argc; i++) {
		//read in data from file
		personFilePtr = fopen(argv[i], "r");
		//read in each line of data from the file
		fscanf(personFilePtr, "%d", &isFLnum);
		if (isFLnum == 1){
			isFL = true;
		}
		else {
			isFL = false;
		}
		fscanf(personFilePtr, "%d", &salary);
		/////get info for struct
		fscanf(personFilePtr, "%lf", &savings);
		fscanf(personFilePtr, "%lf", &checkings);
		fscanf(personFilePtr, "%lf", &debt);
		fscanf(personFilePtr, "%lf", &loan);
		fscanf(personFilePtr, "%d", &yearsWithDebt);
		fscanf(personFilePtr, "%d", &yearsRented);
		fscanf(personFilePtr, "%lf", &debtPaid);
		fscanf(personFilePtr, "%s", fileOutName);

		//create a struct with the info from the file
		struct financialIdentity current = {
			savings,
			checkings,
			debt,
			loan,
			yearsWithDebt,
			yearsRented,
			debtPaid,
			false,
			fileOutName
		};

		//run simulation for given file
		simulate(&current, salary, isFL);

	} // close iteration through argv[]

	return 0;
}//end main



// FOR TESTING PURPOSES: SIMPLE MAIN WITH FL/NFL DEFINED STRUCTS
/////DOES NOT SUPPORT FILE INPUT AND VAIRABLE FILE OUTPUT

/*
int main(){
//initialize individual structs
struct financialIdentity fl = {
5000.0,
0.0,
30100.0,
0.0,
0,
0,
0.0,
false,
"FLoutput.txt"
};
struct financialIdentity nfl = {
5000.0,
0.0,
30100.0,
0.0,
0,
0,
0.0,
false,
"NFLoutput.txt"
};
//simulate the financiallyLiterate person's life
simulate(&fl, 59000, true);
//simulate the non financiallyLiterate person's life
simulate(&nfl, 59000, false);
}
*/
