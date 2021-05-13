public class BasePlusCommissionCompensationModel implements CompensationModel{
    private double baseSalary; // base salary per week
    private double grossSales; // gross weekly sales       
    private double commissionRate; // commission percentage
    
   // constructor
   public BasePlusCommissionCompensationModel(double grossSales,
      double commissionRate, double baseSalary) {
       
      // if grossSales is invalid throw exception
      if (grossSales < 0.0) {
         throw new IllegalArgumentException("Gross sales must be >= 0.0");
      }      

      // if commissionRate is invalid throw exception
      if (commissionRate <= 0.0 || commissionRate >= 1.0) {
         throw new IllegalArgumentException(
            "Commission rate must be > 0.0 and < 1.0");
      }      
      
      if (baseSalary < 0.0) { // validate baseSalary                  
         throw new IllegalArgumentException("Base salary must be >= 0.0");
      }      
      
      this.grossSales = grossSales;
      this.commissionRate = commissionRate;
      this.baseSalary = baseSalary;                
   }

   // set gross sales amount
   public void setGrossSales(double grossSales) {
      if (grossSales < 0.0) {
         throw new IllegalArgumentException("Gross sales must be >= 0.0");
      }      

      this.grossSales = grossSales;
   } 

   // return gross sales amount
   public double getGrossSales() {return grossSales;}

   // set commission rate
   public void setCommissionRate(double commissionRate) {
      if (commissionRate <= 0.0 || commissionRate >= 1.0) {
         throw new IllegalArgumentException(
            "Commission rate must be > 0.0 and < 1.0");
      } 

      this.commissionRate = commissionRate;
   } 

   // return commission rate
   public double getCommissionRate() {return commissionRate;}
   
   // set base salary
   public void setBaseSalary(double baseSalary) {
      if (baseSalary < 0.0) { // validate baseSalary                  
         throw new IllegalArgumentException("Base salary must be >= 0.0");
      }
            
      this.baseSalary = baseSalary;                
   } 

   // return base salary
   public double getBaseSalary() {return baseSalary;}

   // calculate earnings; override method earnings in interface
   @Override                                                            
   public double earnings() {return getBaseSalary() 
           + getGrossSales() * getCommissionRate();}

   // return String representation of BasePlusCommissionEmployee object
   @Override                                                           
   public String toString() {                                          
      return String.format("%s: %n%s: $%,.2f%n%s: $%,.2f%n%s: $%,.2f",                        
         "base plus commission employee", 
         "Gross Sales", getGrossSales(),
         "Commission rate", getCommissionRate(),
         "base salary", getBaseSalary());                              
   }                         
}
