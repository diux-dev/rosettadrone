package sq.rogue.rosettadrone.settings.drone;

import android.os.Bundle;
import android.support.v7.preference.PreferenceFragmentCompat;

import sq.rogue.rosettadrone.R;

public class DroneSettingsFragment extends PreferenceFragmentCompat {
    private static final String TAG = DroneSettingsFragment.class.getSimpleName();
    private static final String PAGE_ID = "drone_config";

    public static DroneSettingsFragment newInstance(String pageID) {
        DroneSettingsFragment droneSettingsFragment = new DroneSettingsFragment();
        Bundle args = new Bundle();
        args.putString(PAGE_ID, pageID);
        droneSettingsFragment.setArguments(args);

        return droneSettingsFragment;
    }

    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        setPreferencesFromResource(R.xml.preferences, rootKey);
    }
}
