import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Stats {

        private City smartCity;

        public Stats(){
            this.smartCity = null;
        }

        public Stats(City smartCity){
            this.smartCity = smartCity;
        }

        public Stats(Stats sts){
            this.smartCity = sts.getSmartCity();
        }

        public City getSmartCity() {return this.smartCity;}

        public void setSmartCity(City smartCity) {this.smartCity = smartCity;}

        public House mostExpensive(){
            double max = 0;

            House casaMax = null;
            ArrayList<Energy> energyF = smartCity.getEnergyF();
            for(House casa : this.smartCity.getHouses()){
                Bill bill = new Bill(1,energyF,casa);
                if(bill.totalBill() > max){
                    max = bill.totalBill();
                    casaMax = casa;
                }
            }
            return casaMax;
        }

        public ArrayList<Bill> energyBills(String energy, double days){
            ArrayList<Bill> bills = new ArrayList<>();
            for (House house : this.smartCity.getHouses()){
                if(house.getEnergy().equals(energy)){
                    Bill bill = new Bill(days,this.smartCity.getEnergyF(),house);
                    bills.add(bill);
                }
            }
            return bills;
        }

        public String mostProfit() {
            StringBuilder sb = new StringBuilder();
            double max = 0;
            Energy maxEnergy = null;

            HashMap<Energy, Double> profits = new HashMap<>();
            for (Energy energy : this.smartCity.getEnergyF()) {
                double profit = 0;
                for (House house : this.smartCity.getHouses()) {
                    if (house.getEnergy().equals(energy.getName())) {
                        Bill bill = new Bill(1, this.smartCity.getEnergyF(), house);
                        profit += bill.totalBill();
                    }

                }
                if (profit > max) {
                    max = profit;
                    maxEnergy = energy;
                }
            }
            sb.append(maxEnergy.toString()).
                    append("\nDaily profit: ").append(String.format("%.02f",max)).
                    append("\n");

            return sb.toString();
        }

        public ArrayList<House> biggestConsumers(int index){
            ArrayList<House> ret = new ArrayList<>();
            double max = this.smartCity.biggestConsume() + 1;
            for (int i = 0; i<index; i++){
                ret.add(this.smartCity.biggestCond(max));
                max = this.smartCity.biggestCond(max).diaryCHouse();
            }

            return ret;
        }


}
