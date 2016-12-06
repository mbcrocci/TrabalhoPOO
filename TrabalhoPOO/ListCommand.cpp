#include "ListCommand.h"


ListCommand::ListCommand ()
{}


ListCommand::~ListCommand ()
{}

void ListCommand::execute ( World & w )
{
	w.list_all_entities ();
}
