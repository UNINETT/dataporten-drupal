<?php
$print_name_provider = "";
if($provider_name == "Dataporten") {
  $icon_pack_classes    = "";
  $print_name_provider  = $provider_name;
}
?>
<span class="<?php print $icon_pack_classes; ?>" title="<?php print $provider_name; ?>"><?php print $print_name_provider; ?></span>
