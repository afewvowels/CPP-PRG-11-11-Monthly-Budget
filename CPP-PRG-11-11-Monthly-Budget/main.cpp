//
//  main.cpp
//  CPP-PRG-11-11-Monthly-Budget
//
//  Created by Keith Smith on 11/9/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A student has established the following monthly budget:
//
//      Housing                 $500.00
//      Utilities               $150.00
//      Household Expenses      $65.00
//      Transportation          $50.00
//      Food                    $250.00
//      Medical                 $30.00
//      Insurance               $100.00
//      Entertainment           $150.00
//      Clothing                $75.00
//      Miscellaneous           $50.00
//
//  Write a program that has a MonthlyBudget structure designed to hold each of these
//  expense categories. The program should pass the structure to a function that asks the
//  user to enter the amounts spent in each budget category during a month. The program
//  should then pass the structure to a function that displays a report indicating the
//  amount over or under in each category, as well as the amount over or under for the
//  entire monthly budget.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct StructBudget
{
    double dblHousing = 500.0;
    double dblUtilities = 150.0;
    double dblHouseholdExpenses = 65.0;
    double dblTransportation = 50.0;
    double dblFood = 250.0;
    double dblMedical = 30.0;
    double dblInsurance = 100.0;
    double dblEntertainment = 150.0;
    double dblClothing = 75.0;
    double dblMiscellaneous = 50.0;
    double dblTotal = dblHousing + dblUtilities + dblHouseholdExpenses + dblTransportation
                        + dblFood + dblMedical + dblInsurance + dblEntertainment + dblClothing
                        + dblMiscellaneous;
};

StructBudget *getMonthlyExpenses();
bool *validateValues(double *);
StructBudget *calculateOverages(StructBudget *);
void displayResults(StructBudget *, StructBudget *);
string *convertToDollar(double *);

int main()
{
    StructBudget *sbMonthCosts = nullptr;
    sbMonthCosts = new StructBudget;
    
    StructBudget *sbBudgetComparison;
    sbBudgetComparison = new StructBudget;
    
    sbMonthCosts = getMonthlyExpenses();
    
    sbBudgetComparison = calculateOverages(sbMonthCosts);
    
    displayResults(sbMonthCosts, sbBudgetComparison);
    
    return 0;
}

StructBudget *getMonthlyExpenses()
{
    StructBudget *sbMonth = nullptr;
    sbMonth = new StructBudget;
    
    cout << "Please enter dollar amounts\n";
    cout << "spent of the following items:\n";
    
    do
    {
        cout << "\tHousing: $";
        cin >> sbMonth->dblHousing;
    } while(!*validateValues(&sbMonth->dblHousing));
    
    do
    {
        cout << "\tUtilities: $";
        cin >> sbMonth->dblUtilities;
    } while(!*validateValues(&sbMonth->dblUtilities));
    
    do
    {
        cout << "\tHousehold Expenses: $";
        cin >> sbMonth->dblHouseholdExpenses;
    } while(!*validateValues(&sbMonth->dblHouseholdExpenses));
    
    do
    {
        cout << "\tTransportation: $";
        cin >> sbMonth->dblTransportation;
    } while(!*validateValues(&sbMonth->dblTransportation));
    
    do
    {
        cout << "\tFood: $";
        cin >> sbMonth->dblFood;
    } while(!*validateValues(&sbMonth->dblFood));
    
    do
    {
        cout << "\tMedical: $";
        cin >> sbMonth->dblMedical;
    } while(!*validateValues(&sbMonth->dblMedical));
    
    do
    {
        cout << "\tInsurance: $";
        cin >> sbMonth->dblInsurance;
    } while(!*validateValues(&sbMonth->dblInsurance));
    
    do
    {
        cout << "\tEntertainment: $";
        cin >> sbMonth->dblEntertainment;
    } while(!*validateValues(&sbMonth->dblEntertainment));
    
    do
    {
        cout << "\tClothing: $";
        cin >> sbMonth->dblClothing;
    } while(!*validateValues(&sbMonth->dblClothing));
    
    do
    {
        cout << "\tMiscellaneous: $";
        cin >> sbMonth->dblMiscellaneous;
    } while(!*validateValues(&sbMonth->dblMiscellaneous));
    
    return sbMonth;
}

bool *validateValues(double *dblValue)
{
    bool *booIsValid = nullptr;
    booIsValid = new bool;
    *booIsValid = false;
    
    if (*dblValue >= 0.0 && *dblValue <= 10000.0)
    {
        *booIsValid = true;
    }
    else
    {
        cout << "Please enter a dollar amount\n";
        cout << "between $0.00 and $10,000.00.\n";
    }
    return booIsValid;
}

StructBudget *calculateOverages(StructBudget *sbMonth)
{
    StructBudget *sbBudget = nullptr;
    sbBudget = new StructBudget;
    
    sbBudget->dblHousing = sbBudget->dblHousing - sbMonth->dblHousing;
    sbBudget->dblUtilities = sbBudget->dblUtilities - sbMonth->dblUtilities;
    sbBudget->dblHouseholdExpenses = sbBudget->dblHouseholdExpenses - sbMonth->dblHouseholdExpenses;
    sbBudget->dblTransportation = sbBudget->dblTransportation - sbMonth->dblTransportation;
    sbBudget->dblFood = sbBudget->dblFood - sbMonth->dblFood;
    sbBudget->dblMedical = sbBudget->dblMedical - sbMonth->dblMedical;
    sbBudget->dblInsurance = sbBudget->dblInsurance - sbMonth->dblInsurance;
    sbBudget->dblEntertainment = sbBudget->dblEntertainment - sbMonth->dblEntertainment;
    sbBudget->dblClothing = sbBudget->dblClothing - sbMonth->dblClothing;
    sbBudget->dblMiscellaneous = sbBudget->dblMiscellaneous - sbMonth->dblMiscellaneous;
    sbBudget->dblTotal = sbBudget->dblTotal - sbMonth->dblTotal;
    
    return sbBudget;
}

void displayResults(StructBudget *sbMonth, StructBudget *sbBudget)
{
    int intSpacing1 = 20;
    int intSpacing2 = 19;
    int intSpacing3 = 15;
    
    cout << left;
    
    cout << "\n\t\t\tMonthly Budget Report\n\n";
    cout << setw(intSpacing1) << "Item";
    cout << setw(intSpacing2) << "Monthly Expenses";
    cout << setw(intSpacing3) << "Over/Under" << endl;
    
    cout << setw(intSpacing1) << "Housing";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblHousing);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblHousing) << endl;
    
    cout << setw(intSpacing1) << "Utilities";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblUtilities);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblUtilities) << endl;
    
    cout << setw(intSpacing1) << "Household Expenses";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblHouseholdExpenses);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblHouseholdExpenses) << endl;
    
    cout << setw(intSpacing1) << "Transportation";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblTransportation);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblTransportation) << endl;
    
    cout << setw(intSpacing1) << "Food";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblFood);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblFood) << endl;
    
    cout << setw(intSpacing1) << "Medical";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblMedical);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblMedical) << endl;
    
    cout << setw(intSpacing1) << "Insurance";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblInsurance);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblInsurance) << endl;
    
    cout << setw(intSpacing1) << "Entertainment";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblEntertainment);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblEntertainment) << endl;
    
    cout << setw(intSpacing1) << "Clothing";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblClothing);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblClothing) << endl;
    
    cout << setw(intSpacing1) << "Miscellaneous";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblMiscellaneous);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblMiscellaneous) << endl;
    
    cout << setw(intSpacing1) << "Total";
    cout << setw(intSpacing2) << *convertToDollar(&sbMonth->dblTotal);
    cout << setw(intSpacing3) << *convertToDollar(&sbBudget->dblTotal) << endl;
    
    cout << endl;
}

string *convertToDollar(double *dblValue)
{
    string *strString = nullptr;
    strString = new string;
    *strString = "$";

    strString->append(to_string(*dblValue));
    strString->erase(strString->length() - 4, 6);
    
    return strString;
}
