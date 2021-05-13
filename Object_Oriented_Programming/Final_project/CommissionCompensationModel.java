public class CommissionCompensationModel implements CompensationModel{
    private double grossSales; // gross weekly sales       
    private double commissionRate; // commission percentage
 
    // two-argument constructor
    public CommissionCompensationModel(double grossSales, double commissionRate) {
 
       // if grossSales is invalid throw exception
       if (grossSales < 0.0) {
          throw new IllegalArgumentException("Gross sales must be >= 0.0");
       }      
 
       // if commissionRate is invalid throw exception
       if (commissionRate <= 0.0 || commissionRate >= 1.0) {
          throw new IllegalArgumentException(
             "Commission rate must be > 0.0 and < 1.0");
       }      
       
       this.grossSales = grossSales;
       this.commissionRate = commissionRate;
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
 
    //Override earning() in interface to calculate the earning 
    @Override
    public double earnings() {
       return getCommissionRate() * getGrossSales();
    } 
 
    // return String representation of CommissionCompensationModel object
    @Override 
    public String toString() {
       return String.format("%s%n%s: %.2f%n%s: %.2f", 
                 "Commission compensation employee:",
                 "gross sales", getGrossSales(), 
                 "commission rate", getCommissionRate());
    } 
 }