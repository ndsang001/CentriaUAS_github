import java.time.LocalDate;

public class PayrollSystemTest {
    public static void main(String[] args) {
       //Create birthday objects
       Date birth1 = new Date(2, 28, 1966);
       Date birth2 = new Date(4, 18, 1970);
       Date birth3 = new Date(5, 22, 1977);
       Date birth4 = new Date(6, 29, 1988);
       // create subclass objects                                          
       SalariedEmployee salariedEmployee =                                 
          new SalariedEmployee("John", "Smith", "111-11-1111", 800.00, birth1);    
       HourlyEmployee hourlyEmployee =                                     
          new HourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40, birth2);  
       CommissionEmployee commissionEmployee =                             
          new CommissionEmployee(                                          
          "Sue", "Jones", "333-33-3333", 10000, .06, birth3);                      
       BasePlusCommissionEmployee basePlusCommissionEmployee =             
          new BasePlusCommissionEmployee(                                  
          "Bob", "Lewis", "444-44-4444", 5000, .04, 300, birth4);                  
 
       System.out.println("Employees processed individually:");
 
       System.out.printf("%n%s%n%s: $%,.2f%n%n", 
          salariedEmployee, "earned", salariedEmployee.earnings());
       System.out.printf("%s%n%s: $%,.2f%n%n",
          hourlyEmployee, "earned", hourlyEmployee.earnings());
       System.out.printf("%s%n%s: $%,.2f%n%n",
          commissionEmployee, "earned", commissionEmployee.earnings());
       System.out.printf("%s%n%s: $%,.2f%n%n", 
          basePlusCommissionEmployee, 
          "earned", basePlusCommissionEmployee.earnings());
 
       // create four-element Employee array
       Employee[] employees = new Employee[4]; 
 
       // initialize array with Employees        
       employees[0] = salariedEmployee;          
       employees[1] = hourlyEmployee;            
       employees[2] = commissionEmployee;        
       employees[3] = basePlusCommissionEmployee;
 
       System.out.printf("Employees processed polymorphically:%n%n");
 
       //Getting the current date value
       LocalDate currentdate = LocalDate.now();
       int currentMonth = currentdate.getMonthValue();
       
       // generically process each element in array employees
       for (Employee currentEmployee : employees) {
          System.out.println(currentEmployee); // invokes toString
 
          // determine whether element is a BasePlusCommissionEmployee
          if (currentEmployee instanceof BasePlusCommissionEmployee) {
             // downcast Employee reference to 
             // BasePlusCommissionEmployee reference
             BasePlusCommissionEmployee employee = 
                (BasePlusCommissionEmployee) currentEmployee;
 
             employee.setBaseSalary(1.10 * employee.getBaseSalary());
 
             System.out.printf(
                "new base salary with 10%% increase is: $%,.2f%n",
                employee.getBaseSalary());
          } 
          
          if(currentEmployee.getMonth() == currentMonth){
              System.out.println("Happy birthday!!!");
              System.out.println("Your gift is 100$!");
              System.out.println("Normal earning: " + currentEmployee.earnings());
              System.out.println("Total earning: " + (currentEmployee.earnings()+100) + "\n");
          } else {
              System.out.printf(
             "earned $%,.2f%n%n", currentEmployee.earnings());
          }
       } 
 
       // get type name of each object in employees array
       for (int j = 0; j < employees.length; j++) {      
          System.out.printf("Employee %d is a %s%n", j,  
             employees[j].getClass().getName());         
       }                                                 
    } 
 } 