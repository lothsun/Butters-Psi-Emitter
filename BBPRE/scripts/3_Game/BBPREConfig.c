class BBPREConfig {

    //Define Config Version
    static const string CONFIG_VERSION = "0.1";

    //config location
    private const static string ModFolder = "$profile:\\BBPRE\\";
    private const static string SettingsConfigFile = "PsiEmitter.json";
    private const static string FileName = "PsiEmitter";
    private const static string FileType = ".json";

    //Config Reference 
    string ConfigVersion = "";
    ref GenSetConf GeneralSettings;
    ref LogConf CFToolsLogging;

    void Load(){
        if (GetGame().IsDedicatedServer()){
            if (FileExist(ModFolder + SettingsConfigFile)){
                //If config exists, load file
                JsonFileLoader<BBPREConfig>.JsonLoadFile(ModFolder + SettingsConfigFile, this);
                Print("[BBPRE] [JSON] Found settings file; Loading Butter's Beyond Psi Emitter settings.");
                // If version mismatch, backup old version of json before replacing it
                if (ConfigVersion != CONFIG_VERSION){
                    JsonFileLoader<BBPREConfig>.JsonSaveFile(ModFolder + FileName + "_old" + FileType, this);
                    Print("[BBPRE] [JSON] New config version found for mod; Backing up old file and saving as " + ModFolder + FileName + "_old" + FileType + " and generating new config file.");
                }
                else {
                    // Config exists and version matches, stop here.
                    return;
                }
            }
        
        Print("[BBPRE] [JSON] Generating settings file.");
        //Save config file version to file
        ConfigVersion = CONFIG_VERSION;
        //Save general settings to file
        GeneralSettings = new GenSetConf;
        //Save CF Tools logging settings to file
        CFToolsLogging = new LogConf; 

        //Save it
        Save();
        }
    };
    void Save(){
        if (!FileExist(ModFolder)){
            //if config folder doesn't exist, create it.
            MakeDirectory(ModFolder);
        }
        //Save JSON Config
        JsonFileLoader<BBPREConfig>.JsonSaveFile(ModFolder + SettingsConfigFile, this);
        Print("[BBPRE] [JSON] Settigns file generation complete!");
    };
};

//general settings config data
class GenSetConf {
    string DebugInfo = "Turns debug mode on to print extra logs to the script.log file.";
    bool DebugLogs = 0;
    string EmitterRadiusInfo = "Sets the Emitter effect radius.";
    int EmitterRadius = 20;
    string EmitterShockDamageInfo = "Sets the shock damage value for the emitter effect.";
    int EmitterShockDamage = 5;
    string EmitterHealthDamageInfo = "Sets the shock damage value for the emitter effect.";
    int EmitterHealthDamage = 5;
};

//cftools logging config data
class LogConf {
    string LoggingInfo = "Requires the ExtraLogs mod by TRG to use this section.";
    bool CatchLogs = 0;
};

//Save config data
protected ref BBPREConfig m_BBPREConfig;
// Helper function to return config data storage object
static BBPREConfig GetBBPRESettingsConfig(){
    if (!m_BBPREConfig){
        Print("[BBPRE] Initializing Butter's Beyond Psi Emitter.");
        Print("[BBPRE] Loading JSON config file. ");
        m_BBPREConfig = new BBPREConfig;

        //Only load JSON config on the server
        if (GetGame().IsServer()){
            m_BBPREConfig.Load();
        }
    }
    return m_BBPREConfig;
};

static void SetBBPREConfig(BBPREConfig config)
{
    Print("[BBPRE] Set config settings from server.");
    m_BBPREConfig = config;
};
