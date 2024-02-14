import java.io.Serializable;

public class Energy implements Serializable {

    private String name;
    private double baseValue;
    private double tax;

    public Energy(){
        this.name = null;
        this.baseValue = 0;
        this.tax = 0;
    }

    public Energy(String name, double baseValue, double tax){
        this.name = name;
        this.baseValue = baseValue;
        this.tax = tax;
    }

    public Energy(Energy energy){
        this.name = energy.getName();
        this.baseValue = energy.getBaseValue();
        this.tax = energy.getTax();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getBaseValue(){
        return this.baseValue;
    }

    public void setBaseValue(double baseValue){
        this.baseValue = baseValue;
    }

    public double getTax(){
        return this.tax;
    }

    public void setTax(double tax){
        this.tax = tax;
    }


    public Energy clone(){
        return new Energy(this);
    }

    public boolean equals(Object o){
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        Energy energy = (Energy) o;
        return this.name == energy.getName() &&
                this.baseValue == energy.getBaseValue() &&
                this.tax == energy.getTax();
    }

    public double moneyFunc(double spent){
        return (this.baseValue * spent * (2 + this.tax)) * 0.7;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Name: ").append(this.getName()).
                append("\nBase Value: ").append(String.format("%.02f",this.getBaseValue())).
                append("\nTax: ").append(String.format("%.02f",this.getTax()));
        return sb.toString();
    }
}
