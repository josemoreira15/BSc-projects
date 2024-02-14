public class SmartSpeaker extends SmartDevice {

    private double volume;
    private String radio;
    private String brand;
    private double diaryConsumption;

    public SmartSpeaker() {
        super();
        this.volume = 0;
        this.radio = null;
        this.brand = null;
        this.diaryConsumption = 0;
    }

    public SmartSpeaker(Mode mode, double code, double price, double volume, String radio, String brand, double diaryConsumption) {
        super(mode,code,price);
        this.volume = volume;
        this.radio = radio;
        this.brand = brand;
        this.diaryConsumption = diaryConsumption;
    }

    public SmartSpeaker(SmartSpeaker ss) {
        super(ss.getMode(),ss.getCode(),ss.getPrice());
        this.volume = ss.getVolume();
        this.radio = ss.getRadio();
        this.brand = ss.getBrand();
        this.diaryConsumption = ss.getDiaryConsumption();
    }

    public double getVolume() {
        return this.volume;
    }

    public void setVolume(double volume) {
        this.volume = volume;
    }

    public String getRadio() {
        return this.radio;
    }

    public void setRadio(String radio) {
        this.radio = radio;
    }

    public String getBrand() {
        return this.brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getDiaryConsumption(){
        return this.diaryConsumption;
    }

    public void setDiaryConsumption(double diaryConsumption){
        this.diaryConsumption = diaryConsumption;
    }

    public SmartSpeaker clone() {
        return new SmartSpeaker(this);
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        SmartSpeaker ss = (SmartSpeaker) o;
        return this.volume == ss.getVolume() &&
                this.radio == ss.getRadio() &&
                this.brand == ss.getBrand() &&
                this.diaryConsumption == ss.getDiaryConsumption();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("SMART SPEAKER").
                append("\nMode: ").append(getMode()).
                append("\nCode: ").append(getCode()).
                append("\nPrice: ").append(getPrice()).
                append("\nVolume: ").append(this.getVolume()).
                append("\nRadio: ").append(this.getRadio()).
                append("\nBrand: ").append(this.getBrand()).
                append("\nDiary Consumption: ").append(this.getDiaryConsumption());


        return sb.toString();
    }

    public double diaryConsumptionF(){
        return 0.5 + 0.01 * this.volume;
    }
}
