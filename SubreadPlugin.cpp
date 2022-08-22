#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SubreadPlugin.h"

void SubreadPlugin::input(std::string file) {
	readParameterFile(file);
}

void SubreadPlugin::run() {

}

void SubreadPlugin::output(std::string file) {
  myCommand += "subread-align";
  addRequiredParameter("-i", "index");
  addRequiredParameter("-r", "forward");
  addRequiredParameter("-t", "DNA");
  addRequiredParameter("-R", "reverse");
  addOptionalParameter("--SAMinput", "SAMinput");
  addOptionalParameter("--BAMinput", "BAMinput");
  addOptionalParameter("--SAMoutput", "SAMoutput");
  addOptionalParameter("-P", "Phred");
  addOptionalParameter("-n", "numselect");
  addOptionalParameter("-m", "consensushit");
  addOptionalParameter("-p", "consensusthreshold");
  addOptionalParameter("-M", "maxmismatch");
  addOptionalParameter("--multiMapping", "multiMapping");
  addOptionalParameter("-B", "maxequal");
  addOptionalParameter("-I", "maxindel");
  addOptionalParameter("--complexIndels", "complexIndels");
  addOptionalParameter("--trim5", "trim5");
  addOptionalParameter("--trim3", "trim3");
  addOptionalParameter("-d", "minfragment");
  addOptionalParameter("-D", "maxfragment");
  addOptionalParameter("-S", "orientation");
  addOptionalParameter("-T", "numthreads");
  addOptionalParameter("--rg-id", "readgroupID");
  addOptionalParameter("--rg", "readgroup");
  addOptionalParameter("-b", "colorspace");
  addOptionalParameter("--DPGapOpen", "DBGapOpen");
  addOptionalParameter("--DPGapExt", "DBGapExt");
  addOptionalParameter("--DPMismatch", "DBMismatch");
  addOptionalParameter("--DPMatch", "DBMatch");
  addOptionalParameter("--sv", "SV");
  addOptionalParameter("-a", "annotation");
  addOptionalParameter("-F", "format");
  addOptionalParameter("-A", "chromosome");
  addOptionalParameter("--gtfFeature", "GTFFeature");
  addOptionalParameter("--gtfAttr", "GTFAttr");
	  myCommand += " -o "+file;


 std::cout << myCommand << std::endl;

 system(myCommand.c_str());
}

PluginProxy<SubreadPlugin> SubreadPluginProxy = PluginProxy<SubreadPlugin>("Subread", PluginManager::getInstance());
