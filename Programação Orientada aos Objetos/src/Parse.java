import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Parse {

    public City parse(){
        City city = new City();
        List<String> lines = readFile("/home/santi/Documents/Universidade/2º Semestre/POO/Trabalho Prático/logs/logs.txt");
        String [] line;
        String lastDivision = null;
        House lastHouse = null;

        double code = 1;

        for (String linee : lines) {
            line = linee.split(":", 2);
            switch(line[0]){
                case "Fornecedor":
                    Energy energy = parseEnergy(line[1].toString());
                    city.addEnergyG(energy);
                    break;
                case "Casa":
                    lastHouse = parseHouse(line[1]);
                    city.addHouse(lastHouse);
                    break;
                case "Divisao":
                    lastDivision = line[1];
                    lastHouse.addDivision(lastDivision);
                    break;
                case "SmartBulb":
                    if (lastDivision == null)
                        System.out.println("Linha inválidaa.");
                    SmartBulb sb = parseSmartBulb(line[1],code);
                    lastHouse.addDevice(code,sb);
                    lastHouse.addDeviceDivision(lastDivision,code);
                    code++;
                    break;
                case "SmartSpeaker":
                    if (lastDivision == null)
                        System.out.println("Linha inválidaa.");
                    SmartSpeaker ss = parseSmartSpeaker(line[1],code);
                    //System.out.println(ss.toString());
                    lastHouse.addDevice(code,ss);
                    lastHouse.addDeviceDivision(lastDivision,code);
                    code++;
                    break;
                case "SmartCamera":
                    if (lastDivision == null)
                        System.out.println("Linha inválidaa.");
                    SmartCamera sc = parseSmartCamera(line[1],code);
                    //System.out.println(sc.toString());
                    lastHouse.addDevice(code,sc);
                    lastHouse.addDeviceDivision(lastDivision,code);
                    code++;
                    break;
                default:
                    System.out.println("Linha inválidaaa.");
                    break;
            }
        }
        //System.out.println("Parsing done!");
        return city;
    }

    public List<String> readFile(String fileName) {
        List<String> lines;
        try { lines = Files.readAllLines(Paths.get(fileName), StandardCharsets.UTF_8); }
        catch(IOException exc) { lines = new ArrayList<>(); }
        return lines;
    }

    public House parseHouse(String input){
        HashMap<Double, SmartDevice> smartDevices = new HashMap<>();
        HashMap<String, List<Double>> divisions = new HashMap<>();
        String [] fields = input.split(",",3);
        String name = fields[0];
        String NIF = fields[1];
        String energy = fields[2];
        return new House(smartDevices,divisions,name,NIF,energy);
    }

    public Energy parseEnergy(String input){
        double randomBase = Math.random();
        double randomTax = Math.random();
        return new Energy(input,randomBase,randomTax);
    }

    public SmartBulb parseSmartBulb(String input, double code){
        String [] fields = input.split(",",3);
        String lampS = fields[0];
        SmartBulb.Lamp lamp = null;
        double dimension = Double.parseDouble(fields[1]);
        double diaryConsumption = Double.parseDouble(fields[2]);
        switch(lampS){
            case "Neutral":
                lamp = SmartBulb.Lamp.Neutral;
                break;
            case "Warm":
                lamp = SmartBulb.Lamp.Warm;
                break;
            case "Cold":
                lamp = SmartBulb.Lamp.Cold;
                break;
        }
        SmartDevice.Mode mode;
        double randomSB = Math.round(Math.random());
        if (randomSB == 1.0)
            mode = SmartDevice.Mode.On;
        else
            mode = SmartDevice.Mode.Off;
        return new SmartBulb(mode,code,15,lamp,dimension,diaryConsumption);
    }

    public SmartSpeaker parseSmartSpeaker(String input,double code){
        String [] fields = input.split(",",4);
        double volume = Double.parseDouble(fields[0]);
        String radio = fields[1];
        String brand = fields[2];
        double diaryConsumption = Double.parseDouble(fields[3]);
        SmartDevice.Mode mode;
        double randomSS = Math.round(Math.random());
        if (randomSS == 1.0)
            mode = SmartDevice.Mode.On;
        else
            mode = SmartDevice.Mode.Off;

        return new SmartSpeaker(mode,code,20,volume,radio,brand,diaryConsumption);
    }

    public SmartCamera parseSmartCamera(String input, double code) {
        String[] fields = input.split(",", 3);
        String resolution = fields[0];
        double size = Double.parseDouble(fields[1]);
        double diaryConsumption = Double.parseDouble(fields[2]);
        SmartDevice.Mode mode;
        double randomSC = Math.round(Math.random());
        if (randomSC == 1.0)
            mode = SmartDevice.Mode.On;
        else
            mode = SmartDevice.Mode.Off;

        return new SmartCamera(mode,code,30,resolution, size, diaryConsumption);
    }
}