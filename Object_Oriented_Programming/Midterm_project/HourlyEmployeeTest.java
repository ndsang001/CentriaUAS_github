public class HourlyEmployeeTest {
    public static void main(String[] args){
        HourlyEmployee hourlyEmployee = new HourlyEmployee(
            "Sang", "Nguyen", "10-03-01", 40, 10.36);
        
        // get hourly employee data
      System.out.println("Employee information obtained by get methods:");
      System.out.printf("%n%s %s%n", "First name is",
         hourlyEmployee.getFirstName());
      System.out.printf("%s %s%n", "Last name is", 
         hourlyEmployee.getLastName());
      System.out.printf("%s %s%n", "Social security number is", 
         hourlyEmployee.getSocialSecurityNumber());
      System.out.printf("%s %.2f%n", "Hours worked is", 
         hourlyEmployee.getHours());
      System.out.printf("%s %.2f%n", "Wage is",
         hourlyEmployee.getWage());
      System.out.printf("%s %.2f%n", "Earning is",
         hourlyEmployee.earnings());

      hourlyEmployee.setHours(56.2);  
      hourlyEmployee.setWage(10.92);
      
      //Invoke toString on HourlyEmployee object using hourlyEmployee variable
      System.out.printf("%n%s%n%s%nEarning: %.2f%n", 
              "Updated employee information obtained by toString", 
              hourlyEmployee, hourlyEmployee.earnings());
       
    }
}
