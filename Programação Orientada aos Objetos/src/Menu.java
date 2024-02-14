import java.io.IOException;
import java.util.Scanner;

public class Menu {

    private boolean exit;
    private City city; //= new Parse();
    private Scanner scannerD; //= new Scanner(System.in);
    private Scanner scannerS; //= new Scanner(System.in);
    private double days;

    public Menu(){
        this.exit = false;
        this.city = new City();
        this.scannerD = null;
        this.scannerS = null;
        this.days = 0;
    }

    public Menu(Boolean exit, City city, Scanner scannerD, Scanner scannerS, double days) {
        this.exit = exit;
        this.city = city;
        this.scannerD = scannerD;
        this.scannerS = scannerS;
        this.days = days;
    }

    public boolean isExit() {
        return this.exit;
    }

    public void setExit(boolean exit) {
        this.exit = exit;
    }

    public City getCity() {
        return this.city;
    }

    public void setCity(City city) {
        this.city = city;
    }

    public Scanner getScannerD() {
        return this.scannerD;
    }

    public void setScannerD(Scanner scannerD) {
        this.scannerD = scannerD;
    }

    public Scanner getScannerS() {
        return this.scannerS;
    }

    public void setScannerS(Scanner scannerS) {
        this.scannerS = scannerS;
    }

    public double getDays() {
        return this.days;
    }

    public void setDays(double days) {
        this.days = days;
    }

    private void printHeader(){
        System.out.println("=======================================================");
        System.out.println("|                       Welcome                       |");
        System.out.println("|              to the SmartCity Simulator             |");
        System.out.println("=======================================================");
    }


    private void printMenu(){
        System.out.println("\n============== RESOURCE MANAGEMENT MENU ==============");
        System.out.println("| 1) Get info about the SmartCity                    |");
        System.out.println("| 2) Bills and Stats                                 |");
        System.out.println("| 3) Change devices and Suppliers                    |");
        System.out.println("| 4) Save APP state                                  |");
        System.out.println("| 5) Change Simulation's days                        |");
        System.out.println("| 0) Exit                                            |");
        System.out.println("======================================================");

    }

    private void printMenu2(){
        System.out.println("\n============== STATS MENU =================");
        System.out.println("| 9) Most expensive house                 |");
        System.out.println("| 10) Supplier with the most profit       |");
        System.out.println("| 11) Bills of a supplier                 |");
        System.out.println("| 12) Most x consumers                    |");;
        System.out.println("===========================================\n");
        System.out.println("15) Go back to the MENU");



    }

    private void printMenu3(){
        System.out.println("\n============== CITY INFO =================");
        System.out.println("| 6) Get info about a SmartDevice         |");
        System.out.println("| 7) Get info about a House               |");
        System.out.println("| 8) Get info about a Supplier            |");
        System.out.println("==========================================\n");
        System.out.println("15) Go back to the MENU");
    }

    private void printMenu4(){
        System.out.println("\n========== REARRANGE CITY ========");
        System.out.println("| 13) Change a SmartDevice mode      |");
        System.out.println("| 14) Change a House's Supplier      |");
        System.out.println("======================================\n");
        System.out.println("15) Go back to the MENU");


    }

    public void runMenu() throws IOException, ClassNotFoundException {
        printHeader();
        loadInicial();
        askNumber();
        printMenu();
        while (!exit) {
            int choice = getInput();
            try {
                performAction(choice);
            } catch (IOException error) {
                throw new RuntimeException(error);
            }
        }
    }

    private int getInput(){
        Scanner sc = new Scanner(System.in);
        int choice = -1;
        while(choice < 0 || choice > 15){
            try{
                System.out.print("\nInsert Option: ");
                choice = Integer.parseInt(sc.nextLine());
            }
            catch (NumberFormatException e){
                System.out.println("Invalid! Try again!");
            }
        }
        return choice;
    }

    private void performAction(int choice) throws IOException {
        Stats stats = new Stats(this.city);
        switch (choice){
            case 0:
                exit = true;
                System.out.println("\n          <<< Simulation Finished >>> \n");
                break;
            case 1:
                clearBash();
                printMenu3();
                break;
            case 2:
                clearBash();
                printMenu2();
                break;
            case 3:
                clearBash();
                printMenu4();
                break;
            case 4:
                this.city.saveState();
                System.out.println("\n == STATE SAVED SUCCESSFULLY == ");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 5:
                //clearBash();
                askNumber();
                clearBash();
                System.out.println("\n == ADVANCED "+this.days+" DAYS SUCCESSFULLY == ");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 6:
                clearBash();
                smartDevice();
                System.out.println("================================\n");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 7:
                clearBash();
                smartHouse();
                System.out.println("================================");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 8:
                clearBash();
                smartSupplier();
                System.out.println("==============================");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 9:
                clearBash();
                System.out.println("================================");
                System.out.println(stats.mostExpensive().toString());
                System.out.println("================================");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 10:
                clearBash();
                System.out.println("================================");
                System.out.print(stats.mostProfit());
                System.out.println("================================");
                System.out.println("\n15) Go back to the MENU");
                break;
            case 11:
                clearBash();
                listBills(stats);
                System.out.println("\n15) Go back to the MENU");
                break;
            case 12:
                clearBash();
                xConsumers(stats);
                System.out.println("\n15) Go back to the MENU");
                break;
            case 13:
                clearBash();
                changeMode();
                System.out.println("\n15) Go back to the MENU");
                break;
            case 14:
                clearBash();
                changeSupplierM();
                System.out.println("\n15) Go back to the MENU");
                break;
            case 15:
                clearBash();
                printMenu();
                break;
        }
    }

    private void cleanShell(int cleanBars){
        for (int i=0; i<cleanBars; i++)
            System.out.print("\n");
    }


    private void smartDevice(){
        System.out.print("\n=> Type the ID of the SmartDevice: ");
        double id = this.scannerD.nextDouble();
        System.out.println("================================");
        System.out.println(this.city.findDevice(id));
    }

    private void smartHouse(){
        System.out.print("\n=> Type the full name of the owner: ");
        String name = this.scannerS.nextLine();
        System.out.println("================================");
        System.out.println(this.city.findHouse(name));
    }

    private void smartSupplier(){
        System.out.print("\n=> Type the name of the Supplier: ");
        String name = this.scannerS.nextLine();
        System.out.println("==============================");
        System.out.println(this.city.findSupplier(name));
    }

    private void askNumber(){
        System.out.print("\n=> Type the number of days you want to simulate: ");
        this.days = scannerD.nextDouble();
        clearBash();
    }

    private void listBills(Stats stats){
        System.out.print("\n=> Type the name of the Supplier: ");
        String supplier = this.scannerS.nextLine();
        System.out.println(stats.energyBills(supplier,this.days));
    }

    private void changeMode(){
        System.out.print("\n=> Type the ID of the SmartDevice: ");
        double id = this.scannerD.nextDouble();
        this.city.changeDeviceMode(id);
        System.out.println("\n -- The mode of your SmartDevice was changed! -- ");
    }

    private void changeSupplierM(){
        System.out.print("\n=> Type the name of the House's owner: ");
        String name = this.scannerS.nextLine();
        System.out.print("\n=> Type the name of the new Supplier: ");
        String energy = this.scannerS.nextLine();
        this.city.changeSupplier(name,energy);
        System.out.println("\n -- The Supplier was changed! -- ");
    }

    private void xConsumers(Stats stats){
        System.out.print("\n=> Type your top consumers: ");
        int nr = this.scannerD.nextInt();
        System.out.println(stats.biggestConsumers(nr));
    }

    private void loadInicial() throws IOException, ClassNotFoundException {
        System.out.println("\n1) Start a new Simulation");
        System.out.println("2) Load Simulation");
        System.out.print("\nInsert option: ");
        int choice = this.scannerD.nextInt();
        if (choice == 2)
            try {
                this.city = this.city.loadState("simulation.obj");
                 System.out.println("\n == STATE LOADED SUCCESSFULLY ==");
            }
        catch(IOException e1){
                System.out.println(e1.getMessage());
        } catch(ClassNotFoundException e2){
                System.out.println(e2.getMessage());
            }
    }
        public static void clearBash(){
            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
    }