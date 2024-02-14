public class SmartCamera extends SmartDevice {

    private String resolution;
    private double size;
    private double diaryConsumption;

    public SmartCamera() {
        super();
        this.resolution = null;
        this.size = 0;
        this.diaryConsumption = 0;
    }

    public SmartCamera(Mode mode, double code, double price, String resolution, double size, double diaryConsumption) {
        super(mode,code,price);
        this.resolution = resolution;
        this.size = size;
        this.diaryConsumption = diaryConsumption;
    }

    public SmartCamera(SmartCamera sc) {
        super(sc.getMode(),sc.getCode(),sc.getPrice());
        this.resolution = sc.getResolution();
        this.size = sc.getSize();
        this.diaryConsumption = sc.getDiaryConsumption();
    }

    public String getResolution() {
        return this.resolution;
    }

    public void setResolution(String resolution) {
        this.resolution = resolution;
    }

    public double getSize() {
        return this.size;
    }

    public void setSize(double size) {
        this.size = size;
    }

    public double getDiaryConsumption(){
        return this.diaryConsumption;
    }

    public void setDiaryConsumption(double diaryConsumption){
        this.diaryConsumption = diaryConsumption;
    }

    public SmartCamera clone() {
        return new SmartCamera(this);
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        SmartCamera sc = (SmartCamera) o;
        return this.resolution == sc.getResolution() &&
                this.size == sc.getSize() &&
                this.diaryConsumption == sc.getDiaryConsumption();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("SMART CAMERA").
                append("\nMode: ").append(getMode()).
                append("\nCode: ").append(getCode()).
                append("\nPrice: ").append(getPrice()).
                append("\nResolution: ").append(this.getResolution()).
                append("\nSize: ").append(this.getSize()).
                append("\nDiary Consumption: ").append(this.getDiaryConsumption());

        return sb.toString();
    }

    public double diaryConsumptionF(){
        String [] parts = this.resolution.split("x",2);
        return 0.000001 * Double.parseDouble(parts[0]) * Double.parseDouble(parts[1]) * this.size;
    }
}
