public class CompositionTest {
    public static void main(String[] args) {
        //Assign CommissionEmployee class reference to 
        //commissionEmployee variable          
        CommissionEmployee commissionEmployee = new CommissionEmployee(
           "Sue", "Jones", "222-22-2222", 10000, .06);                 
  
        //Assign BasePlusCommissionEmployee class reference to 
        //basePlusCommissionEmployee variable      
        BasePlusCommissionEmployee basePlusCommissionEmployee =
           new BasePlusCommissionEmployee(                     
           "Bob", "Lewis", "333-33-3333", 5000, .04, 300);     
  
        //Invoke toString on CommissionEmployee object using commissionEmployee variable
        System.out.printf("%s %s:%n%n%s%n%n", 
           "Call CommissionEmployee's toString with commissionEmployee reference ",
           "to CommissionEmployee object", commissionEmployee.toString());
  
        //Invoke toString on BasePlusCommissionEmployee object using basePlusCommissionEmployee variable      
        System.out.printf("%s %s:%n%n%s%n%n", 
           "Call BasePlusCommissionEmployee's toString with basePlusCommissionEmployee",
           "reference to BasePlusCommissionEmployee object", 
           basePlusCommissionEmployee.toString());
     
     } 
}
