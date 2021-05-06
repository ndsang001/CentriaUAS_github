public class BasePlusCommissionEmployee {
    //BasePlusCommissionEmployee has a relationship with CommissionEmployee
    private CommissionEmployee commissionEmployee;
    //Base salary per week
    private double baseSalary; 
    //Six-argument constructor
    public BasePlusCommissionEmployee(String firstName, String lastName, 
      String socialSecurityNumber, double grossSales, 
      double commissionRate, double baseSalary){
        //Create a commissionEmployee object to pass input variable
        this.commissionEmployee = new CommissionEmployee(firstName, lastName,
                socialSecurityNumber, grossSales, commissionRate);
        
        //If baseSalary is invalid throw exception
        if (baseSalary < 0.0) {                  
            throw new IllegalArgumentException("Base salary must be >= 0.0");
        }       
        
        this.baseSalary = baseSalary;   
    }
    
    //Set base salary
   public void setBaseSalary(double baseSalary) {
      if (baseSalary < 0.0) {                  
         throw new IllegalArgumentException("Base salary must be >= 0.0");
      }       

      this.baseSalary = baseSalary;                
   } 
   
   //Return base salary
   public double getBaseSalary() {return baseSalary;}

   //Calculate earnings by getting the earning from commissionEmployee class
   //and adding with the baseSalary
   public double earnings() {return getBaseSalary() + commissionEmployee.earnings();}

   //Return String representation of BasePlusCommissionEmployee
   @Override
   public String toString() {
      return String.format("%s %s%n%s: %.2f", "base-salaried",
         commissionEmployee.toString(), "base salary", getBaseSalary());   
   }
}