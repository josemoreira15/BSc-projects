import java.util.ArrayList;

public class Bill {

    private double days;
    private ArrayList<Energy> energyF;
    private House house;

    public Bill(double days, ArrayList<Energy> energyF, ArrayList<House> value) {
        this.days = 0;
        this.energyF = new ArrayList<>();
        this.house = null;
    }

    public Bill(double days, ArrayList<Energy> energyF, House house) {
        this.days = days;
        this.energyF = energyF;
        this.house = house;
    }

    public Bill(Bill bill) {
        this.days = bill.getDays();
        this.energyF = bill.getEnergyF();
        this.house = bill.getHouse();
    }

    public double getDays() {return this.days;}

    public void setDays(double days) {this.days = days;}

    public ArrayList<Energy> getEnergyF() {return this.energyF;}

    public void setEnergyF(ArrayList<Energy> energyF) {this.energyF = energyF;}

    public House getHouse() {return this.house;}

    public void setHouse(House house) {this.house = house;}

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Casa: ").append(this.house.getName())
                .append("\nFatura: ").append(String.format("%.02f",this.totalBill()))
                .append("\nConsumo: ").append(String.format("%.02f",this.house.diaryCHouse()))
                .append("\nDias: ").append(this.days);

        return sb.toString();
    }
    public double totalBill(){

        double fTotal = 0;

        for(Energy energy: this.energyF) {
            if(energy.getName().equals(this.house.getEnergy()))
                fTotal = this.days * energy.moneyFunc(this.house.diaryCHouse());
        }
        return fTotal;
    }
}