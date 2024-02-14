import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class City implements Serializable {

    private ArrayList<House> houses;
    private ArrayList<Energy> energyF;
    //private HashMap<Energy,ArrayList<House>> smartCity;

    public City(){
        this.houses = new ArrayList<>();
        this.energyF = new ArrayList<>();
    }

    public City(ArrayList<House> houses, ArrayList<Energy> energyF){
        this.houses = houses;
        this.energyF = energyF;
    }

    public City(City city){
        this.houses = city.getHouses();
        this.energyF = city.getEnergyF();
    }

    public ArrayList<House> getHouses() {
        return this.houses;
    }

    public void setHouses(ArrayList<House> houses) {
        this.houses = houses;
    }

    public ArrayList<Energy> getEnergyF() {
        return energyF;
    }

    public void setEnergyF(ArrayList<Energy> energyF) {
        this.energyF = energyF;
    }

    public void addEnergyG(Energy energy){
        this.energyF.add(energy);
    }
    public void addHouse(House house){
        this.houses.add(house);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Casas: ").append(this.houses).
                append("\nFornecedores: ").append(this.energyF);

        return sb.toString();
    }

    public void removeHouse(House house){
        this.houses.remove(house);
    }

    public void changeDeviceMode(double code){
        for (House house : this.houses){
            house.changeDevice(code);
        }
    }

    public ArrayList<Bill> allBills(double days){
        ArrayList<Bill> bills = new ArrayList<>();
        for(House house : this.houses){
            Bill bill = new Bill(days,this.energyF,house);
            bills.add(bill);
        }
        return bills;
    }

    public String findDevice(double code) {
        SmartDevice sd = null;
        for (House house : this.houses) {
            if(house.findDevice(code) != null)
                sd = house.findDevice(code);
        }

        if (sd != null)
            return sd.toString();
        else
            return "DEVICE NOT FOUND!";
    }

    public String findHouse(String name) {
        House h = null;
        for (House house : this.houses) {
            if(house.getName().equals(name))
                h = house;
        }
        if (h != null)
            return h.toString();
        else
            return "HOUSE NOT FOUND!";
    }

    public String findSupplier(String name){
        Energy e = null;
        for (Energy energy : this.energyF){
            if(energy.getName().equals(name))
                e = energy;
        }
        if (e != null)
            return e.toString();
        else
            return "SUPPLIER NOT FOUND!";
    }

    public void changeSupplier(String name, String energy){

        for (House h : this.houses){
            if(h.getName().equals(name))
                h.setEnergy(energy);
        }
    }

    public double biggestConsume(){
        double max = 0;
        for (House house : this.getHouses()){
            if (house.diaryCHouse() > max){
                max = house.diaryCHouse();
            }
        }
        return max;
    }

    public House biggestCond(double value){
        House h = null;
        double max = 0;
        for (House house : this.getHouses()){
            if (house.diaryCHouse() > max && house.diaryCHouse() < value){
                h = house;
                max = house.diaryCHouse();
            }
        }
        return h;
    }

    public void saveState() throws IOException {
        FileOutputStream f = new FileOutputStream("simulation.obj");
        ObjectOutputStream o = new ObjectOutputStream(f);
        o.writeObject(this);
        o.flush();
        o.close();
    }

    public City loadState(String file) throws IOException, ClassNotFoundException {
        FileInputStream f = new FileInputStream(file);
        ObjectInputStream o = new ObjectInputStream(f);
        City sc = (City) o.readObject();
        o.close();
        return sc;
    }

}