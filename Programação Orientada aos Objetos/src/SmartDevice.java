import java.io.Serializable;

public abstract class SmartDevice implements Serializable {

    public enum Mode{
        On,
        Off
    }

    public Mode mode;
    private double code;
    private double price;

    public abstract double diaryConsumptionF();

    public abstract double getDiaryConsumption();

    public SmartDevice(){
        this.mode = Mode.Off;
        this.code = 0;
        this.price = 0;
    }

    public SmartDevice(Mode mode, double code, double price){
        this.mode = mode;
        this.code = code;
        this.price = price;
    }

    public SmartDevice(SmartDevice sd){
        this.mode = sd.getMode();
        this.code = sd.getCode();
        this.price = sd.getPrice();
    }

    public Mode getMode() {
        return mode;
    }

    public void setMode(Mode mode) {
        this.mode = mode;
    }

    public double getCode() {
        return this.code;
    }

    public void setCode(double code) {
        this.code = code;
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }


    public boolean equals(Object o){
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        SmartDevice sd = (SmartDevice) o;
        return this.mode == sd.getMode() &&
                this.code == sd.getCode() &&
                this.price == sd.getPrice();
    }

}
