
EQUATION("Firm_Desired_Markup")
/*
Firm Variable
*/
	v[11]=V("markup_period");
	v[0]=VL("Firm_Desired_Markup",1);                                             	//strategic markup in the last period
	v[1]= fmod((double) t-1, v[11]);                                         		//divides the time period by 8

	if(v[1]==0)                                                              		//if the rest of the above division is zero, adjust strategic markup
		{
		v[2]=VL("Firm_Avg_Potential_Markup",1);                                     //average potential markup of the firm in the last period        
		v[3]=V("sector_market_share_expansion");                                    //market-share expantion parameter
		v[4]=V("sector_markup_apropriation");                                       //profits apropriation parameter   
		v[5]=V("Firm_Desired_Market_Share");                                        //desired market-share 
		v[6]=VL("Firm_Avg_Market_Share",1);                                    		//firm average market share in the last period   
		v[7]=VL("Firm_Competitiveness",1);                                          //firm's competitiveness in the last period
		v[8]=VL("Sector_Avg_Competitiveness",1);                               		//sector's average competitiveness in the last period
		v[9]=v[3]*((v[7]-v[8])/v[8]);                                          		//how much to adjust based on the percentual diference between firm's competitiveness and sector's average competitiveness and the expantion parameter
		if(v[2]*(1+v[9])>v[0]&&v[6]>v[5])                                      		//if the already adjusted average potential markup is higher than desired strategic markup of the last period and firm's average market share is higher than desired market share
			v[10]=v[0]+v[4]*(v[2]*(1+v[9])-v[0]);                              		//the firm adjusts the strategic markup. 
		else                                                                   		//if the adjusted average potential markup is not higher than desired nor the firm's average market-share is not higher than desired
			v[10]=v[0];                                                        		//strategic markup will be the last period's                                            
		
		v[12]=VL("Firm_Quality",1);
		v[13]=VL("Sector_Avg_Quality",1);
		if(v[13]!=0)
			v[14]=(v[12]-v[13])/v[13];
		else
			v[14]=0;
		v[21]=VL("Firm_Market_Share",1);
		v[22]=VL("Firm_Market_Share",v[11]);
		if(v[22]!=0)
			v[23]=(v[21]-v[22])/v[22];
		else
			v[23]=0;
		v[15]=v[0]*(1+v[4]*v[23]);		
		}
	else                                                                     		//if the rest of the above division is not zero, do not adjust strategic markup
		v[15]=v[0];                                                            		//strategic markup will be the last period's			
RESULT(v[15]) 


EQUATION("Firm_Wage")
/*
Nominal Wage of the firm. It increases year by year depending on inflation and firm's avg productivity. Passtrough parameters are sectorial.
*/
	v[0]=VL("Firm_Wage",1);                                                          	 //firm wage in the last period
	v[11]=V("annual_period");
	v[1]= fmod((double) t,v[11]);                                                        //divide the time period by the annual period parameter
	if(v[1]==0)                                                                      	 //if the rest of the above division is zero (beggining of the year, adjust wages)
		{
		v[2]=VL("Firm_Avg_Productivity", 1);                                           	 //firm average productivity in the last period
		v[3]=VL("Firm_Avg_Productivity", (v[11]+1));                                     //firm average productivity five periods befor
		v[4]=(v[2]-v[3])/v[3];                                                           //annual growth of sector average productivity
		v[5]=V("sector_passthrough_productivity");                                       //pass through of productivity to wages
		v[6]=VLS(GRANDPARENT, "Country_Consumer_Price_Index", 1);                        //price index in the last period
		v[7]=VLS(GRANDPARENT, "Country_Consumer_Price_Index", (v[11]+1));                //price index five periods before
		v[8]=max(0,((v[6]-v[7])/v[7])-v[21]);                                            //annual growth of price index (annual inflation)
		v[9]=V("sector_passthrough_inflation");                                          //pass through of inflation to wages   	
		v[12]=VL("Sector_Employment", 1);                                				 //sector employment in the last period
		v[13]=VL("Sector_Employment", (v[11]+1));                        				 //sector employment five periods before
		if(v[13]!=0)
			v[14]=(v[12]-v[13])/v[13];                                                   //annual growth of sector employment
		else
			v[14]=0;
		v[15]=V("sector_passthrough_employment");
		v[16]=VL("Sector_Capacity_Utilization", 1);
		v[17]=V("sector_desired_degree_capacity_utilization");
		v[18]=v[16]-v[17]>0?1:0;
		v[19]=V("sector_passthrough_capacity");
		v[20]=v[18]>0?1:0;
		v[21]=VS(financial, "target_inflation");
		v[22]=VLS(country, "Country_Annual_CPI_Inflation", 1);
		v[10]=v[0]*(1+v[21]+v[5]*v[4]+v[9]*(v[22]-v[21])+v[15]*v[20]+v[18]*v[19]);                      //current wage will be the last period's multiplied by a rate of growth which is an expected rate on productivity plus an inflation adjustment in the wage price index
		}
	else                                                                             	 //if the rest of the division is not zero, do not adjust wages
		v[10]=v[0];                                                                      //current wages will be the last period's
RESULT(v[10])


EQUATION("Firm_Variable_Cost")
/*
Variable unit cost is the wage cost (nominal wages over productivity) plus intermediate costs
*/
	v[4]=VLS(input, "Sector_Avg_Price",1);
	v[5]=V("sector_input_tech_coefficient");
	v[0]=v[4]*v[5];
	v[1]=V("Firm_Wage");
	v[2]=VL("Firm_Avg_Productivity",1);
	if(v[2]!=0)
		v[3]=(v[1]/v[2])+v[0];
	else
		v[3]=0;
RESULT(v[3])


EQUATION("Firm_Unit_Financial_Cost")
/*
Financial costs include interest payment and debt payment. Unit financial cost is total financial costs divided by effective production.
*/
	v[0]=V("sector_investment_period");
	v[6]=V("sector_desired_degree_capacity_utilization");
	v[4]=0;
	for(i=1; i<=v[0]; i++)
		{
		v[1]=VL("Firm_Interest_Payment",i);
		v[2]=VL("Firm_Productive_Capacity",i);
			if(v[2]!=0)
				v[3]=v[1]/(v[2]*v[6]);
			else
				v[3]=0;
		v[4]=v[4]+v[3];
		}
	v[5]=v[4]/v[0];
RESULT(v[5])


EQUATION("Firm_Financial_Cost_Passtrough")
/*
1 if average market share is greater than desired and if debt rate is greater than desired, otherwise 0.
*/
	v[0]=VL("Firm_Desired_Market_Share",1);
	v[1]=VL("Firm_Avg_Market_Share",1);
	v[2]=VL("Firm_Market_Share",1);
	v[3]=VL("Firm_Debt_Rate",1);
	v[4]=VL("Firm_Desired_Debt_Rate",1);
	v[5]=VL("Firm_Avg_Debt_Rate",1);
	v[6]=V("sector_financial_cost_weight");
	if(v[2]>v[0]&&v[3]>v[4])
		v[7]=v[6];
	else
		v[7]=0;
RESULT(v[7])


EQUATION("Firm_Desired_Price")
/*
Firm's desired price is a desired markup over variable costs.
*/
	v[0]=V("Firm_Desired_Markup");                         						//firm's desired markup
	v[1]=V("Firm_Variable_Cost");                          						//firm's variable cost 
	v[3]=V("Firm_Unit_Financial_Cost");
	v[4]=V("Firm_Financial_Cost_Passtrough");
	v[2]=v[0]*(v[1]+v[3]*v[4]);                                  				//firm's desired price will be the desired markup applied to labor cost plus inputs cost, labor cost defined as wages over productivity
RESULT(max(CURRENT,v[2]))


EQUATION("Firm_Price")
/*
Firm's effective price is a average between the desired price and the sector average price
*/
	v[0]=VL("Firm_Price",1);                                                   //firm's price in the last period
	v[1]=V("Firm_Desired_Price");                                              //firm's desired price
	v[2]=V("sector_strategic_price_weight");                                   //strategic weight parameter
	v[3]=VL("Sector_Avg_Price", 1);                                            //sector average price in the last period
	v[4]=v[2]*(v[1])+(1-v[2])*(v[3]);                                          //firm's price is a average between the desired price and the sector average price
	if(v[1]>0)                                                                 //if desired price is positive
		v[5]=max(0.01,v[4]);                                                   //firm's price can never be zero or lower
	else                                                                       //if desired price is not positive
		v[5]=v[0];                                                             //firm's price will be the last period's
RESULT(v[5])


EQUATION("Firm_Effective_Markup")
/*
Effective Markup is the Effective Price over the Variable Cost
*/
	v[0]=V("Firm_Price");
	v[1]=V("Firm_Variable_Cost");
	if(v[1]!=0)
		v[2]=v[0]/v[1];
	else
		v[2]=0;
RESULT(v[2])


EQUATION("Firm_Desired_Market_Share")
/*
Desired Market Share is a simple average between last period's desired market share and firm's average market share
*/
	v[0]=V("markup_period");
	v[1]=VL("Firm_Desired_Market_Share", 1);                        //desired market share in the last period
	v[2]=VL("Firm_Avg_Market_Share", 1);                        	//firm's average market share (desired)
	v[3]= fmod((double) t-1, v[0]);                               	//devides the last period by eight
	if(v[3]==0)                                                   	//if the rest of the above division is zero, adjust desired market share
		v[4]=(v[1]+v[2])/2;                                         //current desired market share is a simple average between last period's desired market share and firm's average market share
	else                                                          	//if the rest of the above division is not zero, do not adjust desired market share
 		v[4]=v[1];                                                  //firm's desired market share will be equal to the last period's
RESULT(v[4])


EQUATION("Firm_Avg_Market_Share")
/*
Average Market Share between the market share of the firm in the last markup period
*/
	v[0]=V("markup_period");
	v[3]=0;										   						//initializes the sum
	for (i=0; i<=(v[0]-1); i++)											//from 0 to markup period-1 lags
		{
		v[2]=VL("Firm_Market_Share", i);								//computates firm's market share of the current lag
		v[3]=v[3]+v[2];													//sum up firm's lagged market share
		}
	v[4]=v[3]/v[0];														//average firm's market share of the last investment period
RESULT(v[4])


EQUATION("Firm_Potential_Markup")
/*
Potential markup is the sector average price over firm's variable costs
*/
	v[0]=V("Sector_Avg_Price");                                       //sector average price
	v[1]=V("Firm_Variable_Cost");                                     //firm's variable cost
	if(v[1]!=0)                                                       //if firm's variable cost is not zero
		v[2]=v[0]/v[1];                                               //potential markup is the sector average price over firm's variable costs
	else                                                              //if firm's variable cost is zero
		v[2]=0;                                                       //potential markup is zero
RESULT(v[2])


EQUATION("Firm_Avg_Potential_Markup")
/*
Average Potential Markup between the potential markup of the firm in the last 8 periods
*/
	v[0]=V("markup_period");
	v[3]=0;																//initializes the sum
	for (i=0; i<=(v[0]-1); i++)											//from 0 to markup period-1 lags
		{
		v[2]=VL("Firm_Potential_Markup", i);							//computates firm's potential markup of the current lag
		v[3]=v[3]+v[2];													//sum up firm's lagged potential markup
		}
	v[4]=v[3]/v[0];														//average firm's market share of the last potential markup
RESULT(v[4])
