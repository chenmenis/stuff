#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

class CSVRow
{
    public:
        string const& operator[](std::size_t index) const
        {
            return m_data[index];
        }
        size_t size() const
        {
            return m_data.size();
        }
        void readNextRow(std::istream& str)
        {
            string         line;
            getline(str,line);
            _line = line;
            stringstream   lineStream(line);
            string         cell;

            m_data.clear();
            while(std::getline(lineStream,cell,','))
            {
                m_data.push_back(cell);
            }
        }
        string getRawLine() { return _line; }
    private:
        string _line;
        vector<std::string>    m_data;
};

istream& operator>>(std::istream& str,CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

class ReaderLoader{
public:

ReaderLoader();
ReaderLoader(string staticfilei,string dynamicfilei):dynamicfile(dynamicfilei),staticfile(staticfilei){

}

void readStaticInformation();
void readnDumpDynamicInformation();
private:
ifstream dynamicfile;
ifstream staticfile;
unordered_map<string,unordered_map<string,string> > data;

};

void ReaderLoader::readStaticInformation(){
   CSVRow              row;
   CSVRow              header;
   staticfile      >> header;

    unordered_map<string,string> dictionary{
        {"id","Originator Loan ID"},
        {"member_id","Originator Borrower ID"},
        {"loan_amnt","Original Principal"},
        {"term","Term"},
        {"int_rate","Interest Rate"},
        {"installment","Monthly Payment"},
        {"grade","Originator Loan Grade"},
        {"subgrade","Originator Loan Sub Grade"},
        {"home_ownership","Home Ownership Indicator"},
        {"issue_d","Issue Date"},
        {"loan_status","Originator Status"},
        {"desc","Loan Description"},
        {"purpose","Loan Purpose"},
        {"zip_code","zip"},
        {"addr","state"},
        {"inq_last_6mths","Inquiries in the past 6 months"},
        {"last_credit_pull_d","Last Credit Pull Date"},
        {"policy_code","Policy Code"},
        {"emp_title","title"}
   };

   while(staticfile >> row){
        string primekey("");
        unordered_map<string,string>  entry;

        if(row.size()!= header.size()) {

            continue;
        }
        for(int i = 0; i< row.size();i++){

            string column = header[i];

            int origid(0);

            if(dictionary.find(column) != dictionary.end()){
                string value = row[i];

                if(column=="id"){
                    primekey = value;
                    origid = atoi(value.c_str());
                  //  cout << origid << endl;
                }

                if(column=="term"){
                     std::size_t pos = value.find("m");
                     if(pos!=string::npos){
                        value = value.substr(0,value.length()-pos-2);
                     }
                }
                entry[dictionary[column]] = value;
            }


        }

        if(primekey!="") {
           data[primekey] = entry;
        }

   }
return;
}
string wordMonthToInt(string &input){
    string month(input);
    if(month=="JAN") {
        month = "01";
    }
    if(month=="FEB") {
        month = "02";
    }
    if(month=="MAR") {
        month = "03";
    }
    if(month=="APR") {
        month = "04";
    }
    if(month=="MAY") {
        month = "05";
    }
    if(month=="JUN") {
        month = "06";
    }

    if(month=="JUL") {
        month = "07";
    }

    if(month=="AUG") {
        month = "08";
    }

    if(month=="SEP") {
        month = "09";
    }

    if(month=="OCT") {
        month = "10";
    }

    if(month=="NOV") {
        month = "11";
    }

    if(month=="DEC") {
        month = "12";
    }

    return month;
}
string convertSrcDateToPeerIQDate(string s){
    if(s=="") return s;
   // cout << s << endl;
    string month =s.substr(0,3);
    string year =s.substr(3);
    string day="01";
    string delimiter="-";
    string monthConvert(wordMonthToInt(month));
    return year+delimiter+monthConvert+delimiter+day;
}
int convertIQDateInt(string input){
    if(input=="") return 0;
    vector<string> s = split(input,'-');
    string year(s[0]);
    string month(s[1]);
    string day(s[2]);
    return atoi(year.c_str())*12+ atoi(month.c_str());

}
int convertSrcDateToMonths(string s){
    if(s=="") return 0;
    string month =s.substr(0,3);
    string year =s.substr(3);
    string monthConvert(wordMonthToInt(month));
    return atoi(year.c_str())*12+atof(monthConvert.c_str());
}


void ReaderLoader::readnDumpDynamicInformation(){

   CSVRow              row;
   CSVRow              header;
   dynamicfile      >> header;
    // this should really be in some configuration file, but for the sake of test , a bad short cut is taken for the sake of time.
   string dumpheader("Originator,Originator Loan ID,Loan Month,Originator Borrower ID,Months on Balance,Issue date,Loan Type,vintage,Currency,Original Principal,Term,Interest Rate,Coupon,Monthly Payment,Maturity Date,Originator Loan Status,Loan Description,Loan Purpose,FICO Origination,FICO Current,Originator Loan Grade,Originator Loan Sub Grade,Service Fee Rate,Total Service Fee,Policy Code,Outstanding Principal BOP,Outstanding Principal EOP,Outstanding Principal Funded by Investors,Accrued Interest,Principal Received,Interest Received,Fees Received,Total Payment Amount,Total Payment Due,Remaining Term,Charge Off Indicator,Charge Off Amount,Charge Off Date,Post Charge Off Recovery Fee,Post Charge Off Recoveries,Last Credit Pull Date,ninety DPD Accounts Current,sixty DPD Accounts Current,Zip,Home Ownership indicator,Job Title,FICO Range Low,FICO Range High,Inquiries in the past 7 months,State,FICO Range High Origination,FICO Range Low Origination");
   cout << dumpheader << endl;

   while(dynamicfile >> row){
        string primekey("");
        unordered_map<string,string> entry;

        string line = "";
        string originator="";
        string loan_type="";
        string currency="";
        string outstandingPrincipalFundedbyInvestors="";
        string maturityDate="";
        string ninetyDPDAccountsCurrent="";
        string sixtyDPDAccountsCurrent="";


        string orig_id="";
        string orig_borrower_id="";
        string MonthONBal="";
        string LoanMonth="";
        string issueDate="";
        string vintage="";
        string orig_principle="";
        string term="";
        string interestRate="";
        string coupon="";
        string monthlyPayment="";
        string origLoanStatus="";
        string loanDesc="";
        string loanPurp="";
        string ficoOrig="";
        string ficoLow ="";
        string ficoHigh ="";
        string ficoCurrent ="";
        string ficoClow ="";
        string ficoChigh ="";
        string originatorLoanGrade="";
        string originatorLoanSubGrade="";
        string lateFee="";
        string totalreclatfee="";
        string policy="";
        string outstandingPrincipalBOP="";
        string outstandingPrincipalEOP="";
        string accruedInterest="";
        string principleRecieved="";
        string intReceived="";
        string feesReceived="";
        string totalPaymentAmount="";
        string totalPaymentDue="";
        string remainTerm="";
        string chargeOffIndicator="";
        string chargeOffAmt="";
        string charoffDate=""; //chargeoff date;****
        string postChargeOffFee="";
        string postChargeOffRecovery="";
        string lastCreditPullDate="";
        string monthsSinceDQ="";
        string zip="";
        string state="";
        string homeownership="";
        string jobtitle="";
        string inquiries6M="";
        if(header.size()!=row.size()) {
            //should really dump bad data somwhere in log if it were a proper logging system
            continue;
        }
        bool hasStatic(false);

        for(int i = 0; i< row.size();i++){
            string column = header[i];
            string value = row[i];

            if(column=="LOAN_ID"){
                orig_id = value;
                originator="";
                unordered_map<string,string> &entry = data[orig_id];


                orig_borrower_id= entry["Originator Borrower ID"];
                issueDate = entry["Issue Date"];

                orig_principle = entry["Original Principal"];
                term = entry["Term"];
                monthlyPayment = entry["Monthly Payment"];
                origLoanStatus= entry["Originator Loan Status"];
                loanDesc = entry["Loan Description"];
                loanPurp = entry["Loan Purpose"];
                originatorLoanGrade =entry["Originator Loan Grade"];
                originatorLoanSubGrade=entry["Originator Loan Sub Grade"];
                lastCreditPullDate=entry["Last Credit Pull Date"];
                zip = entry["zip"];
                state =entry["state"];
                homeownership =entry["Home Ownership Indicator"];
                jobtitle = entry["title"];

            }
            if(column == "MONTH"){
                LoanMonth= convertSrcDateToPeerIQDate(value);

            }

            if(column == "MOB"){
                MonthONBal= value;
            }


            if(column == "VINTAGE"){
                vintage = value;
            }

            if(column == "InterestRate"){
                interestRate = value;
                stringstream ss(value);
                double numeric;
                ss >> numeric;
                double rate= 100*numeric;
                ss.clear();
                ss << rate;

                coupon = ss.str();

            }
            if(column == "APPL_FICO_BAND"){

                vector<string> fico = split(value,'-');
                if(fico.size()==2) {
                    ficoLow = fico[0];
                    ficoHigh = fico[1];
                    stringstream ss;

                    int fico_low = atoi(fico[0].c_str());
                    int fico_high = atoi(fico[1].c_str());
                    int fico_org = (fico_low + fico_high)/2;
                    ss << fico_org;
                    ficoOrig = ss.str();
                }

            }
            if(column=="Last_FICO_BAND"){

                vector<string> fico = split(value,'-');
                if(fico.size()==2){
                     ficoClow = fico[0];
                     ficoChigh = fico[1];
                    stringstream ss;

                    int fico_low = atoi(fico[0].c_str());
                    int fico_high = atoi(fico[1].c_str());
                    int avg = (fico_low + fico_high)/2;
                    ss << avg;
                    ficoCurrent = ss.str();
                }

            }

            if(column=="collection_recovery_fee"){ //##not sure
                lateFee = value; // service fee
            }

            if(column=="total_rec_late_fee"){
                totalreclatfee = value; //  total fee //# couldn't find on the corresponding column in both static/dyn tables
            }

            if(column=="policy_code"){
                policy = value;
            }
            if(column=="PBAL_BEG_PERIOD"){
                outstandingPrincipalBOP=value;
            }
            if(column=="PBAL_END_PERIOD"){
                outstandingPrincipalEOP=value;
            }
            if(column=="PRNCP_PAID"){
                outstandingPrincipalFundedbyInvestors=value;

            }
            if(column=="PRNCP_PAID"){
                principleRecieved=value;
            }

            if(column=="INT_PAID"){
                intReceived=value;
            }
            if(column=="FEE_PAID"){
                feesReceived=value;
            }

            if(column=="RECEIVED_AMT"){
                totalPaymentAmount=value;
            }

            if(column=="DUE_AMT"){
                totalPaymentDue=value;
            }
            if( column=="CO"){
                chargeOffIndicator=value;
            }

            if(column=="COAMT"){
                chargeOffAmt = value;
            }
            if(column=="PCO_COLLECTION_FEE") {
                postChargeOffFee= value;
            }
            if(column=="PCO_RECOVERY") {
                postChargeOffRecovery= value;
            }
            if(column== "Inquiries6M") {
                inquiries6M = value;
            }
            if(column== "IssuedDate" && issueDate=="") {
                issueDate = convertSrcDateToPeerIQDate(value);

            }
            if(column== "term" && term=="") {
                term = value;
            }





        }

        if(chargeOffIndicator!="1"){
            charoffDate = LoanMonth;
        }
        if(outstandingPrincipalBOP!="" && interestRate!="")
        {
            double outstandingPrincipalBOPD= atof(outstandingPrincipalBOP.c_str());
            double interestRateD = atof(interestRate.c_str());

            double accruedRateD = outstandingPrincipalBOPD*interestRateD/12;
            stringstream ss;
            ss << accruedRateD;
            accruedInterest = ss.str();
        }




        if(term!="" && LoanMonth!="" && issueDate!=""){

            int iterm = atoi(term.c_str());

            int sterm = convertIQDateInt(issueDate);
            int currentterm = convertIQDateInt(LoanMonth);
            int remainingTerm = iterm - (currentterm-sterm);
           stringstream ss;
            ss << remainingTerm;
           remainTerm = ss.str();
        }

        if(term!="" && issueDate !=""){
            int iterm = atoi(term.c_str());
            int otermdate = convertIQDateInt(issueDate);
            int year(otermdate/12);
            int month(otermdate% 12);
            stringstream ss;
            ss << year << "-" << month << "-" << "01";
            maturityDate =  ss.str();

        }
        string delimiter=",";

        line = originator+delimiter+ orig_id + delimiter + LoanMonth + delimiter+ orig_borrower_id+delimiter+ MonthONBal +delimiter
            + issueDate + delimiter + loan_type +delimiter + vintage + delimiter + currency + delimiter + orig_principle +delimiter
            + term + delimiter + interestRate + delimiter + coupon + delimiter + monthlyPayment + delimiter + maturityDate+ delimiter
            + origLoanStatus + delimiter+ loanDesc + delimiter+ loanPurp + delimiter+ ficoOrig + delimiter+ ficoCurrent + delimiter
            + originatorLoanGrade + delimiter + originatorLoanSubGrade + delimiter+ lateFee + delimiter + totalreclatfee + delimiter
            + policy +delimiter+ outstandingPrincipalBOP + delimiter + outstandingPrincipalEOP + delimiter + outstandingPrincipalFundedbyInvestors+delimiter
            + accruedInterest +delimiter+ principleRecieved + delimiter+ intReceived + delimiter+ feesReceived + delimiter + totalPaymentAmount + delimiter
            + totalPaymentDue + delimiter+ remainTerm + delimiter + chargeOffIndicator+ delimiter+ chargeOffAmt + delimiter +charoffDate + delimiter+postChargeOffFee+","
            + postChargeOffRecovery + delimiter+ lastCreditPullDate + delimiter+ ninetyDPDAccountsCurrent +delimiter+ sixtyDPDAccountsCurrent + delimiter+ zip +delimiter
            + homeownership + delimiter + jobtitle + delimiter + ficoChigh + delimiter+ficoClow +delimiter+ inquiries6M +  delimiter + state + delimiter +ficoHigh + delimiter+ ficoLow;

            cout << line << endl;

    }

}

int main(int argc, char* argv[])
{

   /*
        Originator (can't locate the appriate field for this in the two tables)
        Originator Loan ID -
        Loan Month
        Originator Borrower ID
        Months on Balance
        Issue date
        Loan Type -(Can't locate the correponding field in the two tables)
        vintage -
        Currency - ( Can't locate the correponding field in the two tables)
        Original Principal
        Term
        Interest Rate
        Coupon
        Monthly Payment
        Maturity Date
        Originator Loan Status
        Loan Purpose
        Loan Description
        FICO Origination
        FICO Current
        Originator Loan Grade
        Originator Loan Sub Grade
        Service Fee Rate #(Can't find definition used collection_recovery_fee)
        Total Service Fee #(total_rec_late_fee)
        Policy Code
        Outstanding Principal BOP
        Outstanding Principal EOP
        Outstanding Principal Funded by Investors
        Accrued Interest
        Principal Received
        Interest Received
        Fees Received
        Total Payment Amount
        Total Payment Due
        Remaining Term
        Charge Off Indicator
        Charge Off Amount
        Charge Off Date
        Post Charge Off Recovery Fee
        Post Charge Off Recoveries
        Last Credit Pull Date
        ninety DPD Accounts Current(Can't locate the field )
        sixty DPD Accounts Current (Can't locate the field )
        Zip

        Home Ownership indicator
        Job Title ( Can't locate definition ,used emp_title instead, not sure if this the correct one )
        FICO Range Low
        FICO Range High
        Inquiries in the past 6 months
        State
        FICO Range High Origination
        FICO Range Low Origination
        */

    if(argc!=3) {
        cout << "usage: ./peeridq <staticfile> <dynamicfile>" << endl;
        return 0;
    }
    string       staticfile(argv[1]);
    string       dyanmicfile(argv[2]);


    ReaderLoader r(staticfile,dyanmicfile);

    r.readStaticInformation();
    r.readnDumpDynamicInformation();

	return 0;
}
