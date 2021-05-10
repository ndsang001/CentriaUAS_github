public class HourlyEmployee extends Employee{
    //Declare instance variables
    private double hours;
    private double wage;
    //Constructor
    public HourlyEmployee(String firstName, String lastName, 
            String securityNumber, double hours, double wage){
        //Pass parameters into parent class constructor 
        super(firstName, lastName, securityNumber);
        
        //Condition to set the hours and wage
        if(hours < 0 || hours > 168){
            throw new IllegalArgumentException(
                    "The value of hours is between 0 and 168!");
        }
        if(wage < 0){
            throw new IllegalArgumentException(
                    "The wage per hour must be >= 0!");
        }
        
        this.hours = hours;
        this.wage = wage;
    }
    
    //Method to set hours
    public void setHours(double hours){
        //Condition to set the hours
        if(hours < 0 || hours > 168){
            throw new IllegalArgumentException(
                    "The value of hours is between 0 and 168!");
        }
        
        this.hours = hours;
    }
    
    //Method to set wage
    public void setWage(double wage){
        //Condition to set the wage
        if(wage < 0){
            throw new IllegalArgumentException(
                    "The wage per hour must be >= 0!");
        }
        
        this.wage = wage;
    }
    
    //Method to get hours
    public double getHours(){
        return hours;
    }
    
    //Method to get wage
    public double getWage(){
        return wage;
    }
    
    //Override earning() in abstract method to calculate the earning 
    @Override
    public double earnings(){
        //No overtime
        if(hours <= 40){
            return hours * wage;
        }
        //Overtime
        return 40 * wage + (hours - 40) * wage * 1.5;
    }
    
    //Override toString in abstract method
    @Override
    public String toString(){
        return String.format("%s%nhours: %.2f%nwage: %.2f", 
                super.toString(), hours, wage);
    }
}