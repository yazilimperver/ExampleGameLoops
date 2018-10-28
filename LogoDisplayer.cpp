
#include "LogoDisplayer.h"

constexpr char logoMedium[] = R"(
                                                                                 
                                      ./+ooo+/-`                                
                            -/syys//ymmmmmmmmmmmds/.                            
                      ///oydmmmmmmmmmmmmmmmmmmmmmmmmh+.                         
                      `ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy:                       
                    `+hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy.                     
                   :mmmmmmmmmmmmmmmmmmmmmmmmdmmmmmmmmmmmds-                     
                  .mmmmmmmmmmmmmmmmdymmmdo-  .+hmmmmmmmmmmm/                    
                  +mmmmmmmmmmmmmmd+-dmh/`       +mmmmmmmmmmo                    
                 -mmmmmmmmmmmmmd+``/-`           :mmmmmmmmm-                    
               `+mmmmmmmmmmmmh/`                  -hmmmmmmd                     
            ./smmmmmmmmmmmmms+//::/::-`  `-::::::://+hmmmmd                     
           .+osyhhddhmmmmmm-    ..` `/mmmd-    `.. `ommmmmd                     
                     .mmmyy.   ymmm` .s `h    -mmmo +smmmm+                     
                      ymmy-o`  /yyo`-s.  -+`  `shy:-+:mmmo                      
                      ymmm`.//////+ss+++++oys/::::/: ommmo                      
                      ymmdy`  .+ydmmhoo++oshmmh+.   .mdmy                       
                      yhdhmhydmmmmh`smddhdmh`+mmmy//hmymo                       
                      -mmhhdmdmmmd.  /yddy/` -hmmddhdymm-                       
                       :hhhmsddymmmdyo+++oshmmmhhhdymdd:                        
                         ommsmydmdhmhmmmmmmdmmdmsddhmm:                         
                        +mmmmmdmdymhmmdmhmhdmmhmdmmmmmm:                        
                       /mmmmmmmmmdmhmmymmmhmmmmmmmmmmmmm-                       
             ./////////osssssssssssssssssssssssssssssssso/////////-             
             /mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy             
              smmmmmmmmmmmhsyoossmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmd`             
              `hmmmmmmmmmm+oommmmmmmd:ssmmmmmmm++ommmmmmmmmmmmmmm-              
               .dmmmmmmmmm+osmmmmmmmd.mommmmmmm:yommmmmmmmmmmmmm/               
                -mmmmmmmmmoosmmmmmdhy-d+yyhmmhh:h+hhymmmmmmmmmms                
                 /mmmmmmmmsosmmmmo/o+od+oo+h:+++mooo/dmmmmmmmmh                 
                  smmmmmmmh/ommmmmmmy-yhmmmmmmm.ysmmmmmmmmmmmd`                 
                  `hmmmmmmm-ohhhhhmmmoymmmmmmmmysmmmmmmmmmmmm-                  
                   .dmmmmmmmhhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmm/                   
                    -syhmmmmmmmmmmyyyyyysssssymmmmmmmmmmhys+                    
                    ymmmsssosssdmmmmmmmmmmmmd-hmmd.++.+/mmmm`                   
                    .+++++oyooyyy+o++++++++++ooyyyo+oo//++/.                    
                          .s+sdmh:-          `o/mmho/s                          
                          `yys:-.+            .+/+/oys                          
                           `/:  +`             `+.  +.                          
                             .::`                -:/`                           )";

constexpr char logoLarge[] = R"(
                                                                                                                         
                                                                                                                        
                                                        `-/osyhhhhys+/-`                                                
                                            .:+oo+/. ./ydmmmmmmmmmmmmmmmhs/.                                            
                                       `-/sdmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmho-                                         
                                 +ooosydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo-                                      
                                 `ommmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh/`                                   
                                 ./hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo:.                                
                              `:ydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds:                                
                             -ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms:`                                
                            .dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyooshmmmmmmmmmmmmmmmmmmh:                               
                            ymmmmmmmmmmmmmmmmmmmmmmmmd+mmmmmmy/.`   `:sdmmmmmmmmmmmmmmmmd.                              
                           `mmmmmmmmmmmmmmmmmmmmmmmd+.ommmmy:`         .smmmmmmmmmmmmmmmm/                              
                           +mmmmmmmmmmmmmmmmmmmmmdo..smdy+-             `+mmmmmmmmmmmmmmm-                              
                          :mmmmmmmmmmmmmmmmmmmmdo. `::-.                  +mmmmmmmmmmmmmy                               
                        `+dmmmmmmmmmmmmmmmmmmdo.                           /dmmmmmmmmmmm+                               
                      ./hmmmmmmmmmmmmmmmmmmy/.                              .sdmmmmmmmmm/                               
                  `.:sdmmmmmmmmmmmmmmmmmmdyo+oo++++//:-..`    `.-:///+++++//:-:+dmmmmmmm/                               
                 /shmmmmmmmmmmmmmmmmmmmmd+--..`` ``..-:+yhyssyhs/-..``````..-/ydmmmmmmmm/                               
                 ``.-::/+oossooodmmmmmmmo      .:+/:`   :mdhhmh       `:/+:`  .mmmmmmmmm-                               
                                .mmmmmsss     .dmmmmo   -d. `oh       ymmmmh` .dommmmmmy`                               
                                 ymmmm+.d`    .dmmmms  `s+   `y-      hmmmmd` o//mmmmmy`                                
                                 ommmms +y-````-+oo/..:ss`    .s/.````./oo+-.+o ommmmm.                                 
                                 ommmmd` -+ooooooooooso/-::///::osoo+++//+++o:  hmmmmm/                                 
                                 ommmmms       ``:+shdmmmmmmmmmmmmdhs/.`       -mmmmms.                                 
                                 smddhmmo`  `-ohmmmmmdho/:---::/+yhmmmmy/`    `hmhmmd`                                  
                                 omydymmdhssdmmmmmmmo`ommdhhhhddmh`.hmmmmdo-`-ymmsmmd                                   
                                 :mhdmhhymmmmmmmmmm+  `smmmmmmmmy.  `hmmmmmmmhhhdhmms                                   
                                  smmmsydmdmhmmmmmh-`   .+yhhyo-   ./ymmmmhmdyhsdmmm.                                   
                                  `ommssmmshymmsmmmmmyo+::---:/+sydmmmddmhhm/mmdmmm:                                    
                                    .odmmmoymydsmmmymmmdmmmmmmmmmmmmmmddm+mm+mmmms.                                     
                                     `ymmmhhmyhmmymhmmmymmmmdmmmmymmmhmmm+mmsmmmm+                                      
                                    `hmmmmmmmhdmm+mmmymdmdmmymmhmsmmdsmmmsmmmmmmmmo                                     
                                   `hmmmmmmmmmmmm+mmmommmsmmdmmommmmmhmmmmmmmmmmmmmo                                    
                                   smmmmmmmmmmmmmmmmmhmmmsmmmmmhmmmmmmmmmmmmmmmmmmmm+                                   
                     `````````````.+ooooooooooooooooooooo+oooooooooooooooooooooooooo+``````````````                     
                    sddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd-                   
                    +mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmd.                   
                    `ymmmmmmmmmmmmmmmmmmhhdhyyyysdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm:                    
                     `dmmmmmmmmmmmmmmmmy.s++ossyhmmmmmmmhssmmmmmmmmmmmmdyshmmmmmmmmmmmmmmmmmmmmmmmo                     
                      -mmmmmmmmmmmmmmmm+/h/mmmmmmmmmmmm+.yohmmmmmmmmmmd-:d/mmmmmmmmmmmmmmmmmmmmmmy`                     
                       /mmmmmmmmmmmmmmm+:h+mmmmmmmmmmmm:-dohmmmmmmmmmmh.+m/mmmmmmmmmmmmmmmmmmmmmd`                      
                        ommmmmmmmmmmmmms-h+mmmmmmmmmmmm/-m+hmmmmmmmmmmd`yd/mmmmmmmmmmmmmmmmmmmmm-                       
                        `ymmmmmmmmmmmmms:y+mmmmmmmmmdhh/:m+shhhhmmmdhhh`yd:hhhydmmmmmmmmmmmmmmm/                        
                         .dmmmmmmmmmmmmy/s+mmmmmmm+ossssymyssso:hh/ossssddssss+/mmmmmmmmmmmmmmo                         
                          :mmmmmmmmmmmmm:o/mmmmmmmo/++/-/m/+o+oomh/+++:-dh:o+o+hmmmmmmmmmmmmmy`                         
                           +mmmmmmmmmmmm///mmmmmmmmmmmm--m/mmmmmmmmmmms.yshmmmmmmmmmmmmmmmmmd.                          
                            smmmmmmmmmmm+/+hmmmmmmmmmmmo-oymmmmmmmmmmmd-/ommmmmmmmmmmmmmmmmm:                           
                            `hmmmmmmmmmmh:osssssssymmmmmddmmmmmmmmmmmmmddmmmmmmmmmmmmmmmmmm+                            
                             .dmmmmmmmmmmmdhhhdhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms                             
                              :hdddmmmmmmmmmmmmmmmmddddddddddddddddddmmmmmmmmmmmmmmmmddddy`                             
                              `+sssdmmmmmmmmmmmmmmmssssssssssssssssosmmmmmmdmddmdmdmhssso:                              
                              ommmmd+yy+d+yy+d+mmmmmmmmmmmmmmmmmmmm+-smmmmh.o-:o.y.ommmmmm.                             
                              :dddddshhsdshysdsdddddddddddddddddddds+yddddh/s++s/y/sddddd+                              
                               `........os/-+ssss+-+................//:sssss/:/o+.......`                               
                                        y++sohmmm::+                `y.ymmmhss+:y                                       
                                        s+:ohdhhy`s`                 -s.ymmdhs+:h`                                      
                                        :dhd:    /:                   -s.:``./hys                                       
                                         .+/    :o                     .s-    -y`                                       
                                           :s/./s                       `++``/+`                                        
                                             .-.                          ./+:                                          )";

// Ghost font. http://patorjk.com/software/taag/#p=testall&h=3&v=0&f=Train&t=YAZILIMPERVER
constexpr char logoText[] = R"(
             ('-.      .-') _                        _   .-')     _ (`-.   ('-. _  .-')       (`-.     ('-. _  .-')   
            ( OO ).-. (  OO) )                      ( '.( OO )_  ( (OO  )_(  OO( \( -O )    _(OO  )_ _(  OO( \( -O )  
  ,--.   ,--/ . --. ,(_)----.  ,-.-') ,--.     ,-.-'),--.   ,--._.`     (,------,------.,--(_/   ,. (,------,------.  
   \  `.'  /| \-.  \|       |  |  |OO)|  |.-') |  |OO|   `.'   (__...--''|  .---|   /`. \   \   /(__/|  .---|   /`. ' 
 .-')     .-'-'  |  '--.   /   |  |  \|  | OO )|  |  |         ||  /  | ||  |   |  /  | |\   \ /   / |  |   |  /  | | 
(OO  \   / \| |_.'  (_/   /    |  |(_/|  |`-' ||  |(_|  |'.'|  ||  |_.' (|  '--.|  |_.' | \   '   /,(|  '--.|  |_.' | 
 |   /  /\_ |  .-.  |/   /___ ,|  |_.(|  '---.,|  |_.|  |   |  ||  .___.'|  .--'|  .  '.'  \     /__)|  .--'|  .  '.' 
 `-./  /.__)|  | |  |        (_|  |   |      (_|  |  |  |   |  ||  |     |  `---|  |\  \    \   /    |  `---|  |\  \  
   `--'     `--' `--`--------' `--'   `------' `--'  `--'   `--'`--'     `------`--' '--'    `-'     `------`--' '--' 
)";

constexpr char logoText2[] = R"( `
__   _____   ___________ _     ________  _________ ___________ _   _ ___________ 
\ \ / / _ \ |___  /_   _| |   |_   _|  \/  || ___ \  ___| ___ \ | | |  ___| ___ \
 \ V / /_\ \   / /  | | | |     | | | .  . || |_/ / |__ | |_/ / | | | |__ | |_/ /
  \ /|  _  |  / /   | | | |     | | | |\/| ||  __/|  __||    /| | | |  __||    / 
  | || | | |./ /____| |_| |_____| |_| |  | || |   | |___| |\ \\ \_/ / |___| |\ \ 
  \_/\_| |_/\_____/\___/\_____/\___/\_|  |_/\_|   \____/\_| \_|\___/\____/\_| \_|
)";

constexpr char logoText3[] = R"(
     )           ) (   (    (      *    (       (              (     
  ( /(  (     ( /( )\ ))\ ) )\ ) (  `   )\ )    )\ )           )\ )  
  )\()) )\    )\()(()/(()/((()/( )\))( (()/((  (()/((   (  (  (()/(  
 ((_)((((_)( ((_)\ /(_)/(_))/(_)((_)()\ /(_))\  /(_))\  )\ )\  /(_)) 
__ ((_)\ _ )\ _((_(_))(_)) (_)) (_()((_(_))((_)(_))((_)((_((_)(_))   
\ \ / (_)_\(_|_  /|_ _| |  |_ _||  \/  | _ | __| _ \ \ / /| __| _ \  
 \ V / / _ \  / /  | || |__ | | | |\/| |  _| _||   /\ V / | _||   /  
  |_| /_/ \_\/___||___|____|___||_|  |_|_| |___|_|_\ \_/  |___|_|_\  
                                                                     
)";

constexpr char snakeLogo[] = R"(                                                                                                                        
                                                      .-/+oosssyyyyyysoo+/-.                                            
                                                 ./ohNMMMMMMMMMMMMMMMMMNmmNMNmyo/-                                      
                                               /yNMMMMMMMMMMMMMMMMMMMMMh    :NMMMMNh+-                                  
                                             -dMMMMMMMMMMMmhysosyhmMMMMMmdhsdMMMMMMMMNmo                                
                                            /NMMMMMMMMMmo-         yMMMMMMMdo:---/oNMMMy                                
                                           .NMMMMMMMMMo             mMMMMMm        /MMm                                 
                                           oMMMMMMMMMs              oMMMMMd         mM:                                 
                                           oMMMMMMMMMs              :MMMMMMy        s/                                  
                                           :MMMMMMMMMMs.             ohmMMMMm+.                                         
                                            sMMMMMMMMMMms-             .-ohmMMNmmm+                                     
                                             sMMMMMMMMMMMNmy/:.             -+ymy:                                      
                                              /dMMMMMMMMMMMMMNNmhso/::-.                                                
                                               .+dMMMMMMMMMMMMMMMMMMMNNmmdhyo/-                                         
                                                  :sdMMMMMMMMMMMMMMMMMMMMMMMMMNmy/.                                     
                                                     -+ydmMMMMMMMMMMMMMMMMMMMMMMMMmy-                                   
                                                         --:+syhdmNMMMMMMMMMMMMMMMMMNy.                                 
                                   :+osss+:.                     ..-/shmMMMMMMMMMMMMMMm/                                
                                -smNMMMMMMMmy/                         .:smMMMMMMMMMMMMN/                               
                               +mMMMMMMMMMMMMMms.                         ./dMMMMMMMMMMMN-                              
                              /MMMMMMMho+oymNMMMNy:                         .sMMMMMMMMMMMs                              
                              NMMMMMMs      :smMMMMh/.                        yMMMMMMMMMMm                              
                             .MMMMMMM/        .+dNMMMms:.                     .MMMMMMMMMMN                              
                              NMMMMMMd.          :smMMMMmyo/-.. .--.           NMMMMMMMMMd                              
                              oMMMMMMMh.           ./sdNNMMMMNmdhs/.          /MMMMMMMMMMo                              
                               yMMMMMMMNo.             .:/+o+/:-             -mMMMMMMMMMm                               
                                oNMMMMMMMNs:.                               /mMMMMMMMMMN-                               
                                 -hMMMMMMMMMds:.                         .:hMMMMMMMMMMm:                                
                                   :hNMMMMMMMMMNdy+:..                ./smMMMMMMMMMMMh-                                 
                                     -omMMMMMMMMMMMMMNmdhyyyssoossyydmMMMMMMMMMMMMMm+                                   
                                        :ohNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd/                                     
                                           .:oymMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdo-                                       
                                                 :+shdNMMMMMMMMMMMMMMMMMNmyo:.                                          
                                                        .-:/+++ooo++/:-.                                                
                                                                                                                        
			                      ~~~~~ WELCOME TO uSNAKE GAME ~~~~~
)";

void LogoDisplayer::DisplaySnakeLogo()
{
	std::cout << snakeLogo << endl;
	return;

}

void LogoDisplayer::DisplayYazilimPerverLogo1()
{
	std::cout << logoMedium << endl;
	return;	 
}

void LogoDisplayer::DisplayYazilimPerverLogo2()
{
	std::cout << logoLarge << endl;
	return;
}

void LogoDisplayer::DisplayYazilimPerverLogoText1()
{
	std::cout << logoText << endl;
   	return;	
}

void LogoDisplayer::DisplayYazilimPerverLogoText2()
{
	std::cout << logoText2 << endl;
	return;
}

void LogoDisplayer::DisplayYazilimPerverLogoText3()
{
	std::cout << logoText3 << endl;
	return;
}
