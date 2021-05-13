public class CompensationModelTest {
    public static void main(String[] args){
        //Create employee compensation objects
        HourlyCompensationModel hourlyCompensationModel = 
                new HourlyCompensationModel(45, 10.36);
        
        CommissionCompensationModel commissionCompensationModel = 
                new CommissionCompensationModel(5000, 0.3);
        
        SalariedCompensationModel salariedCompensationModel =
                new SalariedCompensationModel(2000);
        
        BasePlusCommissionCompensationModel basePlusCommissionCompensationModel = 
                new BasePlusCommissionCompensationModel(6000, 0.2, 1000);
        
        //Create employee objects and pass compensation models into employee objects
        Employee hourlyEmployee = new Employee("Sang", "Nguyen",
                "10-03-01", hourlyCompensationModel);
        
        Employee commissionEmployee = new Employee("Tuan", "Nguyen",
                "10-07-01", commissionCompensationModel);
        
        Employee salariedEmployee = new Employee("Nhu", "Nguyen",
                "23-08-99", salariedCompensationModel);
        
        Employee basePlusCommissionEmployee = new Employee("Loan", "Nguyen",
                "04-06-00", basePlusCommissionCompensationModel);
        
        /*
        System.out.println("Employee processed individually: ");
        
        System.out.printf("%s%nEarnings: %.2f%n",hourlyEmployee, hourlyEmployee.earnings());
        System.out.printf("%n%s%nEarnings: %.2f%n",commissionEmployee, commissionEmployee.earnings());
        System.out.printf("%n%s%nEarnings: %.2f%n",salariedEmployee, salariedEmployee.earnings());
        System.out.printf("%n%s%nEarnings: %.2f%n",basePlusCommissionEmployee, basePlusCommissionEmployee.earnings());
        */
        
        //Create four-element Employee array
        Employee[] employees = new Employee[4];
        
        //Initialize array with Employees
        employees[0] = hourlyEmployee;
        employees[1] = commissionEmployee;
        employees[2] = salariedEmployee;
        employees[3] = basePlusCommissionEmployee;
        
        System.out.println("\n\nEmployees processed polymorphically "
                + "before changing compensation type:\n");
        
        //Generically process each element in array employees
        for(Employee employee: employees){
            System.out.println(employee); //Invokes toString
            
            System.out.printf("Earnings $%,.2f%n%n", employee.earnings());
        }
        
        //Create new compensation model objects
        HourlyCompensationModel hourlyCompensationModel2 = 
                new HourlyCompensationModel(66, 10.51);
        
        CommissionCompensationModel commissionCompensationModel2 = 
                new CommissionCompensationModel(17000, 0.09);
        
        SalariedCompensationModel salariedCompensationModel2 =
                new SalariedCompensationModel(2789);
        
        BasePlusCommissionCompensationModel basePlusCommissionCompensationModel2 = 
                new BasePlusCommissionCompensationModel(9800, 0.089, 900);
        
        //Set new compensation model objects for the employees
        hourlyEmployee.setCompensationModel(basePlusCommissionCompensationModel2);
        commissionEmployee.setCompensationModel(salariedCompensationModel2);
        salariedEmployee.setCompensationModel(commissionCompensationModel2);
        basePlusCommissionEmployee.setCompensationModel(hourlyCompensationModel2);
        
        System.out.println("\n\nEmployees processed polymorphically "
                + "after changing compensation type:\n");
        
        //Print new employee info 
        for(Employee employee: employees){
            System.out.println(employee); //Invokes toString
            
            System.out.printf("Earnings $%,.2f%n%n", employee.earnings());
        }
    }
}