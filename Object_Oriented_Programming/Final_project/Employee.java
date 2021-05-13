public class Employee {
   private final String firstName;
   private final String lastName;
   private final String socialSecurityNumber;
   private CompensationModel compensationModel; //Declare compensationModel object

   // constructor
   public Employee(String firstName, String lastName, 
      String socialSecurityNumber, CompensationModel compensationModel) {
      this.firstName = firstName;
      this.lastName = lastName;
      this.socialSecurityNumber = socialSecurityNumber;
      this.compensationModel = compensationModel;
   } 

   // return first name
   public String getFirstName() {return firstName;}

   // return last name
   public String getLastName() {return lastName;}

   // return social security number
   public String getSocialSecurityNumber() {return socialSecurityNumber;}
   
   // set the compensationModel
   public void setCompensationModel(CompensationModel compensationModel){
       this.compensationModel = compensationModel;
   }
   
   // get the compensationModel
   public CompensationModel getCompensationModel(){ return compensationModel;}
   
   // return the earnings of the compensation model
   public double earnings(){
       return compensationModel.earnings();
   }
   
   // return String representation of Employee object
   @Override
   public String toString() {
      return String.format("%s %s%nsocial security number: %s%n%s", 
         getFirstName(), getLastName(), getSocialSecurityNumber(),
         compensationModel.toString());
   }
}
