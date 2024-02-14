public class SmartBulb extends SmartDevice {

    public enum Lamp {
        Neutral,
        Warm,
        Cold
    }

    private Lamp lamp;
    private double dimension;
    private double diaryConsumption;

    public SmartBulb() {
        super();
        this.lamp = Lamp.Neutral;
        this.dimension = 0;
        this.diaryConsumption = 0;
    }

    public SmartBulb(Mode mode,double code, double price, Lamp lamp, double dimension, double diaryConsumption) {
        super(mode,code,price);
        this.lamp = lamp;
        this.dimension = dimension;
        this.diaryConsumption = diaryConsumption;
    }

    public SmartBulb(SmartBulb sb) {
        super(sb.getMode(),sb.getCode(),sb.getPrice());
        this.lamp = sb.getLamp();
        this.dimension = sb.getDimension();
        this.diaryConsumption = sb.getDiaryConsumption();
    }

    public Lamp getLamp() {
        return this.lamp;
    }

    public void setLamp(Lamp lamp) {
        this.lamp = lamp;
    }

    public double getDimension() {
        return this.dimension;
    }

    public void setDimension(double dimension) {
        this.dimension = dimension;
    }

    public double getDiaryConsumption(){
        return this.diaryConsumption;
    }

    public void setDiaryConsumption(double diaryConsumption){
        this.diaryConsumption = diaryConsumption;
    }

    public SmartBulb clone() {
        return new SmartBulb(this);
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        SmartBulb sb = (SmartBulb) o;
        return this.lamp == sb.getLamp() &&
                this.dimension == sb.getDimension() &&
                this.diaryConsumption == sb.getDiaryConsumption();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("SMART BULB").
                append("\nMode: ").append(getMode()).
                append("\nCode: ").append(getCode()).
                append("\nPrice: ").append(getPrice()).
                append("\nType: ").append(this.getLamp()).
                append("\nSize: ").append(this.getDimension()).
                append("\nDiary Consumption: ").append(this.getDiaryConsumption());

        return sb.toString();
    }

    public double diaryConsumptionF(){
        double type;
        if(this.lamp == Lamp.Warm)
            type = 1;
        else if(this.lamp == Lamp.Neutral)
            type = 0.5;
        else
            type = 2;

        return type + 1.5;
    }
}
