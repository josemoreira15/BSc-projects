import java.io.Serializable;
import java.util.*;

public class House implements Serializable {

    private HashMap<Double, SmartDevice> smartDevices;
    private HashMap<String, List<Double>> divisions;
    private String name;
    private String NIF;
    private String energy;

    public House() {
        this.smartDevices = new HashMap<>();
        this.divisions = new HashMap<>();
        this.name = null;
        this.NIF = null;
        this.energy = null;
    }

    public House(HashMap<Double, SmartDevice> smartDevices, HashMap<String, List<Double>> divisions, String name, String NIF, String energy) {
        this.smartDevices = smartDevices;
        this.divisions = divisions;
        this.name = name;
        this.NIF = NIF;
        this.energy = energy;
    }

    public House(House house) {
        this.smartDevices = house.getSmartDevices();
        this.divisions = house.getDivisions();
        this.name = house.getName();
        this.NIF = house.getNIF();
        this.energy = house.getEnergy();
    }

    public HashMap<Double, SmartDevice> getSmartDevices() {
        return smartDevices;
    }

    public void setSmartDevices(HashMap<Double, SmartDevice> smartDevices) {
        this.smartDevices = smartDevices;
    }

    public HashMap<String, List<Double>> getDivisions() {
        return divisions;
    }

    public void setDivisions(HashMap<String, List<Double>> divisions) {
        this.divisions = divisions;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNIF() {
        return this.NIF;
    }

    public void setNIF(String NIF) {
        this.NIF = NIF;
    }

    public String getEnergy() {
        return this.energy;
    }

    public void setEnergy(String energy) {
        this.energy = energy;
    }

    public House clone() {
        return new House(this);
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        House h = (House) o;
        return this.smartDevices == h.getSmartDevices() &&
                this.divisions == h.getDivisions() &&
                this.name == h.getName() &&
                this.NIF == h.getNIF() &&
                this.energy == h.getEnergy();
    }

    public void turnOnOffAll(String division, SmartDevice.Mode mode) {
        List<Double> codes = new ArrayList<>();
        for (Map.Entry<String, List<Double>> entry : this.divisions.entrySet()) {
            if (entry.getKey() == division)
                codes = entry.getValue();
        }

        for (Map.Entry<Double, SmartDevice> entry : this.smartDevices.entrySet()) {
            for (double code : codes) {
                if (code == entry.getKey())
                    entry.getValue().setMode(mode);
            }
        }
    }

    public void changeDevice(double code) {
        for (Map.Entry<Double, SmartDevice> entry : this.smartDevices.entrySet()) {
            if (code == entry.getKey()) {
                if (entry.getValue().mode == SmartDevice.Mode.On)
                    entry.getValue().setMode(SmartDevice.Mode.Off);
                else
                    entry.getValue().setMode(SmartDevice.Mode.On);
            }
        }
    }

    public double diaryCHouse() {
        double result = 0;

        for (Map.Entry<Double, SmartDevice> entry : this.smartDevices.entrySet())
            if (entry.getValue().mode == SmartDevice.Mode.On)
                result += entry.getValue().getDiaryConsumption();

        return result;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Owner name: ").append(this.getName()).
                append("\nNIF: ").append(this.getNIF()).
                append("\nEnergy Supplier: ").append(this.getEnergy()).
                append("\nDiary Expense: ").append(String.format("%.02f",this.diaryCHouse()));
                //append("\nDivisões: ").append(this.getDivisions()).
                //append("\nSmartDevices: ").append(this.getSmartDevices()).

        return sb.toString();
    }

    public void addDeviceDivision(String division, double code) {
        for (Map.Entry<String, List<Double>> entry : this.divisions.entrySet()) {
            if (entry.getKey() == division)
                entry.getValue().add(code);
        }
    }

    public void addDevice(double code, SmartDevice sd) {
        this.smartDevices.put(code, sd);
    }

    public void addDivision(String division){
        List<Double> codes = new ArrayList<>();
        this.divisions.put(division,codes);
    }

    public SmartDevice findDevice(double code){
        SmartDevice sd = null;
        for (Map.Entry<Double, SmartDevice> entry : this.smartDevices.entrySet()) {
            if (entry.getKey() == code)
                sd = entry.getValue();
        }
        return sd;
    }

}

